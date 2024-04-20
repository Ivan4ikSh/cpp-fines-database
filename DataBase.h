#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "domain.h"

using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Data;
using namespace System::Collections::Generic;

namespace FinesDB {
    const std::string connection_settings = "Data Source=DESKTOP-8JT83U5\\SQLEXPRESS;Initial Catalog=Fines;Integrated Security=True";

    ref class DataBase {
    public:
        DataBase() {
            try {
                // Попытка подключения к базе данных с отключенной проверкой сертификата
                sql_connection_->ConnectionString = gcnew String(connection_settings.c_str());
                sql_connection_->Open();
                Console::WriteLine("Соединение с базой данных успешно установлено.");
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка подключения: " + ex->Message);
            }

            current_date_ = DateTime(constants::current_date.year, constants::current_date.month, constants::current_date.day);
        }

        array<String^>^ GetTableData(commands::Table command) {
            List<String^>^ list = gcnew List<String^>();

            try {
                SqlCommand^ query;
                switch (command)
                {
                case commands::ARTICLE:
                    query = gcnew SqlCommand("SELECT article FROM FineList", sql_connection_);
                    break;
                case commands::INTER:
                    query = gcnew SqlCommand("SELECT fine_name FROM FineList", sql_connection_);
                    break;
                case commands::PLATE:
                    query = gcnew SqlCommand("SELECT car_plate FROM Drivers", sql_connection_);
                    break;
                default:
                    break;
                }
                SqlDataReader^ reader = query->ExecuteReader();

                while (reader->Read()) {
                    String^ str = reader->GetString(0);
                    list->Add(str);
                }

                reader->Close();
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
            }

            return list->ToArray();
        }
        String^ FindDriverByPlate(String^ plate) {
            try {
                // Формируем SQL-запрос с использованием параметров для предотвращения SQL-инъекций
                String^ queryText = "SELECT driver_name FROM Drivers WHERE car_plate = @plate";
                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);
                query->Parameters->AddWithValue("@plate", plate); // Добавляем параметр

                // Выполняем запрос к базе данных
                SqlDataReader^ reader = query->ExecuteReader();

                // Проверяем, есть ли результаты
                if (reader->Read()) {
                    String^ driverName = safe_cast<String^>(reader["driver_name"]); // Получаем имя водителя
                    reader->Close();
                    return driverName; // Возвращаем имя водителя
                }
                else {
                    reader->Close();
                    return "Водитель не найден";
                }
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
                return "Ошибка выполнения запроса";
            }
        }
        domain::FineInfo^ FindFineInfo(commands::Table command, String^ by) {
            domain::FineInfo^ result = gcnew domain::FineInfo();

            try {
                SqlCommand^ fineQuery;
                switch (command) {
                case commands::ARTICLE:
                    fineQuery = gcnew SqlCommand("SELECT fine_name, punishment, need_evacuation FROM FineList WHERE article = @article", sql_connection_);
                    fineQuery->Parameters->AddWithValue("@article", by);
                    break;
                case commands::INTER:
                    fineQuery = gcnew SqlCommand("SELECT article, punishment, need_evacuation FROM FineList WHERE fine_name = @fine_name", sql_connection_);
                    fineQuery->Parameters->AddWithValue("@fine_name", by);
                    break;
                default:
                    break;
                }
                SqlDataReader^ fineReader = fineQuery->ExecuteReader();

                // Если найдена информация о штрафе
                if (fineReader->Read()) {
                    switch (command) {
                    case commands::ARTICLE:
                        result->fine_name = fineReader->IsDBNull(fineReader->GetOrdinal("fine_name")) ? nullptr : safe_cast<String^>(fineReader["fine_name"]);
                        break;
                    case commands::INTER:
                        result->article = fineReader->IsDBNull(fineReader->GetOrdinal("article")) ? nullptr : safe_cast<String^>(fineReader["article"]);
                        break;
                    default:
                        break;
                    }                    
                    result->punishment = fineReader->IsDBNull(fineReader->GetOrdinal("punishment")) ? nullptr : safe_cast<String^>(fineReader["punishment"]);
                    result->need_evacuation = fineReader->IsDBNull(fineReader->GetOrdinal("need_evacuation")) ? nullptr : safe_cast<Int32^>(fineReader["need_evacuation"]);
                    fineReader->Close();
                }
                else {
                    fineReader->Close();
                    result->punishment = "Штрафная статья не найдена";
                    return result;
                }

                return result;
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
                return result;
            }
        }

        int FindId(commands::Table command, String^ by) {
            try {
                String^ queryText;
                switch (command) {
                case commands::ARTICLE:
                    queryText = "SELECT id FROM FineList WHERE article = @by";
                    break;
                case commands::PLATE:
                    queryText = "SELECT id FROM Drivers WHERE car_plate = @by";
                    break;
                case commands::VIOLATION:
                    queryText = "SELECT id FROM VIOLATION WHERE id = @by";
                    break;
                default:
                    break;
                }
                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);
                query->Parameters->AddWithValue("@by", by);

                SqlDataReader^ reader = query->ExecuteReader();
                if (reader->Read()) {
                    int id = safe_cast<int>(reader["id"]);
                    reader->Close();
                    return id;
                }
                else {
                    reader->Close();
                    return 0;
                }
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
                return 0;
            }
        }

        void InsertViolation(domain::ViolationInfo^ violation) {
            try {
                String^ queryText = "INSERT INTO Violations (driver_id, fine_id, is_evacuated, fine_cost, violation_day) VALUES (@driver_id, @fine_id, @is_evacuated, @fine_cost, @violation_day); SELECT SCOPE_IDENTITY();";
                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);

                query->Parameters->AddWithValue("@driver_id", violation->driver_id);
                query->Parameters->AddWithValue("@fine_id", violation->fine_id);
                query->Parameters->AddWithValue("@is_evacuated", violation->is_evacuated);
                query->Parameters->AddWithValue("@fine_cost", CountFinePercent(violation));
                query->Parameters->AddWithValue("@violation_day", current_date_);

                Object^ result = query->ExecuteScalar();
                violation->violation_id = Convert::ToInt32(result);
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
            }
        }
        void InsertEvacuation(domain::EvacuationInfo^ evacuation) {
            try {
                // Подготовка SQL-запроса
                String^ queryText = "INSERT INTO Evacuations (driver_id, violation_id, evacuation_cost, storage_cost, receipt_date, return_date) VALUES (@driver_id, @violation_id, @evacuation_cost, @storage_cost, @receipt_date, @return_date)";
                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);

                // Добавление параметров
                query->Parameters->AddWithValue("@driver_id", evacuation->driver_id);
                query->Parameters->AddWithValue("@violation_id", evacuation->violation_id);
                query->Parameters->AddWithValue("@evacuation_cost", evacuation->evacuation_cost);
                query->Parameters->AddWithValue("@storage_cost", evacuation->storage_cost);

                // Добавление параметра с строкой текущей даты и времени
                query->Parameters->AddWithValue("@receipt_date", current_date_);
                query->Parameters->AddWithValue("@return_date", DBNull::Value);

                // Выполнение запроса
                query->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
            }
        }
        void InsertPayment(commands::Table command, domain::PaymentInfo^ payment) {
            try {
                // Подготовка SQL-запроса
                String^ queryText;
                switch (command) {
                case commands::EVACUATION:
                    queryText = "INSERT INTO EvacuationsPayments (driver_id, evacuation_id, payment_data, amount_paid) VALUES (@driver_id, @type_id, @payment_data, @amount_paid)";
                    break;
                case commands::FINE:
                    queryText = "INSERT INTO FinesPayments (driver_id, violation_id, payment_data, amount_paid) VALUES (@driver_id, @type_id, @payment_data, @amount_paid)";
                    break;
                default:
                    break;
                }
                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);

                //// Добавление параметров
                query->Parameters->AddWithValue("@driver_id", payment->driver_id);
                query->Parameters->AddWithValue("@type_id", payment->type_id);
                query->Parameters->AddWithValue("@payment_data", DateTime::Today);
                query->Parameters->AddWithValue("@amount_paid", payment->amount_paid);
                
                query->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
            }
        }
        void UpdateEvacuationeReturnDate(int violation_id) {
            try {
                String^ queryText = "UPDATE Evacuations "
                                    "   SET return_date = @return_date "
                                    "WHERE violation_id = @vioviolation_id; ";
                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);

                query->Parameters->AddWithValue("@return_date", current_date_);
                query->Parameters->AddWithValue("@vioviolation_id", violation_id);

                query->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
            }
        }

        DataTable^ UpdatePaymentsTable(commands::Table command, [[maybe_unused]] String^ value) {
            try {
                String^ queryText;
                switch (command) {
                case commands::ALL:
                    queryText = "SELECT "
                                "   d.car_plate AS 'Номер машины', "
                                "   d.driver_name AS 'ФИО', "
                                "   CASE WHEN e.return_date IS NOT NULL THEN(e.evacuation_cost + e.storage_cost * DATEDIFF(MONTH, e.receipt_date, e.return_date)) "
                                "        ELSE 0.0 "
                                "   END AS 'Сумма к оплате', "
                                "   'Эвакуация' AS 'Тип платежа', "
                                "   'Не оплачено' AS 'Состояние оплаты', "
                                "   fl.article AS 'Статья нарушения' "
                                "FROM Evacuations e "
                                "   JOIN Drivers d ON e.driver_id = d.id "
                                "   LEFT JOIN EvacuationsPayments ep ON e.id = ep.evacuation_id "
                                "   LEFT JOIN Violations v ON e.violation_id = v.id "
                                "   LEFT JOIN FineList fl ON v.fine_id = fl.id "
                                "WHERE ep.driver_id IS NULL "
                                "UNION ALL "
                                "SELECT "
                                "   d.car_plate AS 'Номер машины', "
                                "   d.driver_name AS 'ФИО', "
                                "   v.fine_cost AS 'Сумма', "
                                "   'Штраф' AS 'Тип платежа', "
                                "   'Не оплачено' AS 'Состояние оплаты', "
                                "   fl.article AS 'Статья нарушения' "
                                "FROM Violations v "
                                "   JOIN Drivers d ON v.driver_id = d.id "
                                "   JOIN FineList fl ON v.fine_id = fl.id "
                                "   LEFT JOIN FinesPayments fp ON v.id = fp.violation_id "
                                "WHERE v.fine_cost > 0 AND fp.driver_id IS NULL;";
                    break;
                case commands::PLATE:
                    queryText = "SELECT "
                                "   d.car_plate AS 'Номер машины', "
                                "   d.driver_name AS 'ФИО', "
                                "   CASE WHEN e.return_date IS NOT NULL THEN(e.evacuation_cost + e.storage_cost * DATEDIFF(MONTH, e.receipt_date, e.return_date)) "
                                "        ELSE 0.0 "
                                "   END AS 'Сумма к оплате', "
                                "   'Эвакуация' AS 'Тип платежа', "
                                "   'Не оплачено' AS 'Состояние оплаты', "
                                "   fl.article AS 'Статья нарушения' "
                                "FROM Evacuations e "
                                "   JOIN Drivers d ON e.driver_id = d.id "
                                "   LEFT JOIN EvacuationsPayments ep ON e.id = ep.evacuation_id "
                                "   LEFT JOIN Violations v ON e.violation_id = v.id "
                                "   LEFT JOIN FineList fl ON v.fine_id = fl.id "
                                "WHERE ep.driver_id IS NULL AND d.car_plate = @car_plate "
                                "UNION ALL "
                                "SELECT "
                                "   d.car_plate AS 'Номер машины', "
                                "   d.driver_name AS 'ФИО', "
                                "   v.fine_cost AS 'Сумма', "
                                "   'Штраф' AS 'Тип платежа', "
                                "   'Не оплачено' AS 'Состояние оплаты', "
                                "   fl.article AS 'Статья нарушения' "
                                "FROM Violations v "
                                "   JOIN Drivers d ON v.driver_id = d.id "
                                "   JOIN FineList fl ON v.fine_id = fl.id "
                                "   LEFT JOIN FinesPayments fp ON v.id = fp.violation_id "
                                "WHERE v.fine_cost > 0 AND d.car_plate = @car_plate AND fp.driver_id IS NULL;";
                    break;
                case commands::FINE:
                    queryText = "SELECT "
                                "   d.car_plate AS 'Номер машины', "
                                "   d.driver_name AS 'ФИО', "
                                "   v.fine_cost AS 'Сумма', "
                                "   'Штраф' AS 'Тип платежа', "
                                "   'Не оплачено' AS 'Состояние оплаты', "
                                "   fl.article AS 'Статья нарушения' "
                                "FROM Violations v "
                                "   JOIN Drivers d ON v.driver_id = d.id "
                                "   JOIN FineList fl ON v.fine_id = fl.id "
                                "   LEFT JOIN FinesPayments fp ON v.id = fp.violation_id "
                                "WHERE v.fine_cost > 0 AND fp.driver_id IS NULL ";
                    queryText += (value != nullptr) ? "AND d.car_plate = @car_plate" : "";
                    break;
                case commands::EVACUATION:
                    queryText = "SELECT "
                                "   d.car_plate AS 'Номер машины', "
                                "   d.driver_name AS 'ФИО', "
                                "   CASE WHEN e.return_date IS NOT NULL THEN(e.evacuation_cost + e.storage_cost * DATEDIFF(MONTH, e.receipt_date, e.return_date)) "
                                "        ELSE 0.0 "
                                "   END AS 'Сумма к оплате', "
                                "   'Эвакуация' AS 'Тип платежа', "
                                "   'Не оплачено' AS 'Состояние оплаты', "
                                "   fl.article AS 'Статья нарушения' "
                                "FROM Evacuations e "
                                "   JOIN Drivers d ON e.driver_id = d.id "
                                "   LEFT JOIN EvacuationsPayments ep ON e.id = ep.evacuation_id "
                                "   LEFT JOIN Violations v ON e.violation_id = v.id "
                                "   LEFT JOIN FineList fl ON v.fine_id = fl.id "
                                "WHERE ep.driver_id IS NULL ";
                    queryText += (value != nullptr) ? " AND d.car_plate = @car_plate" : "";
                    break;

                default:
                    break;
                }

                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);
                if (value != nullptr) {
                    query->Parameters->AddWithValue("@car_plate", value);
                }

                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query);
                DataTable^ dataTable = gcnew DataTable();
                adapter->Fill(dataTable);

                return dataTable;
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
                return nullptr;
            }
        }
        DataTable^ UpdatePaymentsForUser(String^ value) {
            try {
                String^ queryText = "SELECT "
                                    "    e.id AS 'type_id', "
                                    "    'Эвакуация' AS 'Тип платежа', "
                                    "    fl.article AS 'Статья нарушения', "
                                    "    CASE WHEN e.return_date IS NOT NULL THEN(e.evacuation_cost + e.storage_cost * DATEDIFF(MONTH, e.receipt_date, e.return_date)) "
                                    "         ELSE 0.0 "
                                    "    END AS 'Сумма к оплате', "
                                    "    DATEADD(MONTH, 1, e.return_date) AS 'Срок оплаты' "
                                    "FROM Evacuations e "
                                    "JOIN Drivers d ON e.driver_id = d.id "
                                    "LEFT JOIN Violations v ON e.violation_id = v.id "
                                    "LEFT JOIN FineList fl ON v.fine_id = fl.id "
                                    "LEFT JOIN EvacuationsPayments ep ON e.id = ep.evacuation_id "
                                    "LEFT JOIN FinesPayments fp ON v.id = fp.violation_id "
                                    "WHERE d.car_plate = @car_plate AND fp.driver_id IS NOT NULL AND ep.driver_id IS NULL "
                                    "UNION ALL "
                                    "SELECT "
                                    "    v.id AS 'type_id', "
                                    "    'Штраф' AS 'Тип платежа', "
                                    "    fl.article AS 'Статья нарушения', "
                                    "    v.fine_cost AS 'Сумма к оплате', "
                                    "    DATEADD(MONTH, 1, v.violation_day) AS 'Срок оплаты' "
                                    "FROM Violations v "
                                    "JOIN Drivers d ON v.driver_id = d.id "
                                    "JOIN FineList fl ON v.fine_id = fl.id "
                                    "LEFT JOIN FinesPayments fp ON v.id = fp.violation_id "
                                    "LEFT JOIN Evacuations e ON v.id = e.violation_id "
                                    "WHERE d.car_plate = @car_plate AND v.fine_cost > 0 AND fp.driver_id IS NULL;";

                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);
                if (value != nullptr) {
                    query->Parameters->AddWithValue("@car_plate", value);
                }

                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query);
                DataTable^ dataTable = gcnew DataTable();
                adapter->Fill(dataTable);

                return dataTable;
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
                return nullptr;
            }
        }

        DataTable^ ProfitTableStatistics() {
            try {
                String^ queryText = "SELECT 'Реальная' AS [Тип прибыли], "
                    "SUM(CASE WHEN MONTH(payment_data) BETWEEN 1 AND 3 THEN amount_paid ELSE 0 END) AS [1 квартал], "
                    "SUM(CASE WHEN MONTH(payment_data) BETWEEN 4 AND 6 THEN amount_paid ELSE 0 END) AS [2 квартал], "
                    "SUM(CASE WHEN MONTH(payment_data) BETWEEN 7 AND 9 THEN amount_paid ELSE 0 END) AS [3 квартал], "
                    "SUM(CASE WHEN MONTH(payment_data) BETWEEN 10 AND 12 THEN amount_paid ELSE 0 END) AS [4 квартал], "
                    "SUM(amount_paid) AS [Годовая сумма] "
                    "FROM ( "
                    "SELECT amount_paid, payment_data, YEAR(payment_data) AS [Год] FROM FinesPayments "
                    "UNION ALL "
                    "SELECT amount_paid, payment_data, YEAR(payment_data) AS [Год] FROM EvacuationsPayments "
                    ") AS CombinedPayments "
                    "GROUP BY YEAR(payment_data) "
                    "UNION ALL "
                    "SELECT 'Потенциальная' AS [Тип прибыли], "
                    "SUM(CASE WHEN MONTH(payment_data) BETWEEN 1 AND 3 THEN amount_paid + amount_paid / 3 ELSE 0 END) AS [1 квартал], "
                    "SUM(CASE WHEN MONTH(payment_data) BETWEEN 4 AND 6 THEN amount_paid + amount_paid / 3 ELSE 0 END) AS [2 квартал], "
                    "SUM(CASE WHEN MONTH(payment_data) BETWEEN 7 AND 9 THEN amount_paid + amount_paid / 3 ELSE 0 END) AS [3 квартал], "
                    "SUM(CASE WHEN MONTH(payment_data) BETWEEN 10 AND 12 THEN amount_paid + amount_paid / 3 ELSE 0 END) AS [4 квартал], "
                    "SUM(amount_paid + amount_paid / 3) AS [Годовая сумма] "
                    "FROM ( "
                    "SELECT amount_paid, payment_data, YEAR(payment_data) AS [Год] FROM FinesPayments "
                    "UNION ALL "
                    "SELECT amount_paid, payment_data, YEAR(payment_data) AS [Год] FROM EvacuationsPayments "
                    ") AS CombinedPayments "
                    "GROUP BY YEAR(payment_data)";


                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);

                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query);
                DataTable^ dataTable = gcnew DataTable();
                adapter->Fill(dataTable);

                return dataTable;
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
                return nullptr;
            }
        }
        DataTable^ MostLawersTableStatistics() {
            try {
                String^ queryText = "SELECT TOP 5 "
                                    "ROW_NUMBER() OVER (ORDER BY COUNT(*) DESC) AS [Место], "
                                    "Drivers.driver_name AS [ФИО], "
                                    "Drivers.car_plate AS [Номер авто], "
                                    "COUNT(*) AS [Кол-во нарушений], "
                                    "SUM(Violations.fine_cost) AS [Штрафов на сумму] "
                                    "FROM Violations "
                                    "INNER JOIN Drivers ON Violations.driver_id = Drivers.id "
                                    "GROUP BY Drivers.driver_name, Drivers.car_plate "
                                    "ORDER BY [Место]";


                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);

                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query);
                DataTable^ dataTable = gcnew DataTable();
                adapter->Fill(dataTable);

                return dataTable;
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
                return nullptr;
            }
        }
        DataTable^ MostFinersTableStatistics() {
            try {
                String^ queryText = "SELECT TOP 5 "
                    "ROW_NUMBER() OVER (ORDER BY COUNT(*) DESC) AS [Место], "
                    "FineList.article AS [Статья], "
                    "FineList.fine_name AS [Трактовка], "
                    "COUNT(*) AS [Кол-во нарушений], "
                    "SUM(Violations.fine_cost) AS [Штрафов на сумму] "
                    "FROM Violations "
                    "INNER JOIN FineList ON Violations.fine_id = FineList.id "
                    "GROUP BY FineList.article, FineList.fine_name "
                    "ORDER BY [Место]";

                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);

                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query);
                DataTable^ dataTable = gcnew DataTable();
                adapter->Fill(dataTable);

                return dataTable;
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
                return nullptr;
            }
        }

        array<String^>^ GetNotificationsByPlate(String^ plate) {
            List<String^>^ list = gcnew List<String^>();

            DataTable^ dataTable = UpdatePaymentsForUser(plate);
            int count = 0;

            for each (DataRow ^ row in dataTable->Rows) {
                String^ paymentType = safe_cast<String^>(row["Тип платежа"]);
                DateTime^ ovedue = safe_cast<DateTime^>(row["Срок оплаты"]);

                if (paymentType == "Штраф" && ovedue->Date < current_date_.Date) {
                    count++;
                    list->Add("Просрочен штраф по статье " + safe_cast<String^>(row["Статья нарушения"])->ToString());
                }
            }
            
            if (count>=3) {
                list->Add("Вам выписана повестка в суд за " + count.ToString() + " не оплаченных штрафа/ов");
            }
            else if (IsGoodDriver(plate)) {
                list->Add("Сегодня " + current_date_.ToShortDateString() + " - больше года без аварий и дтп. Вы молодец!");
            }
            else {
                list->Add("Здесь нет уведомлений. Это значит, что вы хороший водитель :)");
            }
            return list->ToArray();
        }

        ~DataBase() {
            sql_connection_->Close();
            Console::WriteLine("Сервер отключился :(");
        }
    private:
        SqlConnection^ sql_connection_ = gcnew SqlConnection();
        DateTime current_date_;

        double CountFinePercent(domain::ViolationInfo^ violation) {
            try {
                String^ query_find = "SELECT v.violation_day "
                                     "FROM Violations v "
                                     "WHERE v.driver_id = @driver_id "
                                     "ORDER BY v.violation_day DESC;";

                SqlCommand^ query = gcnew SqlCommand(query_find, sql_connection_);
                query->Parameters->AddWithValue("@driver_id", violation->driver_id);
                SqlDataReader^ reader = query->ExecuteReader();

                int violation_count = 0;
                DateTime violationDate;

                while (reader->Read()) {
                    ++violation_count;
                    violationDate = safe_cast<DateTime>(reader["violation_day"]);
                }
                reader->Close();

                if (violation_count > 0) {
                    TimeSpan difference = current_date_ - violationDate;
                    int daysDifference = difference.Days;

                    double new_fine = violation->fine_cost + violation->fine_cost * constants::FinePersent();

                    if (daysDifference <= 365) {
                        violation->fine_cost = new_fine;
                    }
                }
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
            }

            return violation->fine_cost;
        }
        bool IsGoodDriver(String^ plate) {
            try {
                int driver_id = FindId(commands::PLATE, plate);

                String^ queryText = "SELECT MAX(violation_day) AS 'Последняя дата аварии' "
                                    "FROM[Fines].[dbo].[Violations] "
                                    "WHERE driver_id = @driver_id; ";

                SqlCommand^ query = gcnew SqlCommand(queryText, sql_connection_);
                query->Parameters->AddWithValue("@driver_id", driver_id);

                Object^ result = query->ExecuteScalar();

                if (result != nullptr) {
                    DateTime maxViolationDay = Convert::ToDateTime(result);
                    DateTime nextYear = maxViolationDay.AddYears(1);

                    if (current_date_ >= nextYear) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
                
            }
            catch (Exception^ ex) {
                Console::WriteLine("Ошибка выполнения запроса: " + ex->Message);
                return false;
            }
        }//баг с датой
    };
}
