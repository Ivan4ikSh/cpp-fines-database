#pragma once
#include "DataBase.h"
#include "domain.h"

namespace FinesDatabase {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Violations
	/// </summary>
	public ref class Violations : public System::Windows::Forms::Form
	{
	public:
		Violations(void)
		{
			InitializeComponent();
			InitalizeAddingComponets();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Violations()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ BackBtn;
	private: System::Windows::Forms::Label^ PlateLabel;
	private: System::Windows::Forms::Label^ HumanFIOLabel;
	private: System::Windows::Forms::ComboBox^ PlateInput;
	private: System::Windows::Forms::Label^ FIOLabel;
	private: System::Windows::Forms::ComboBox^ ArticleInput;
	private: System::Windows::Forms::Label^ ArticeLabel;
	private: System::Windows::Forms::ComboBox^ InterpretationInput;
	private: System::Windows::Forms::Label^ InterpretationLabel;
	private: System::Windows::Forms::CheckBox^ NeedEvacuationCheckBox;
	private: System::Windows::Forms::Label^ FineLabel;
	private: System::Windows::Forms::TextBox^ FineInput;
	private: System::Windows::Forms::Label^ FineInfoLabel;
	private: System::Windows::Forms::Label^ PunishmentLabel;
	private: System::Windows::Forms::Label^ HintLabel;
	private: System::Windows::Forms::Button^ NextBtn;
	private: System::Windows::Forms::TextBox^ StorageCostInput;
	private: System::Windows::Forms::TextBox^ EvacuationCostInput;
	private: System::Windows::Forms::Label^ EvacuationCostLabel;
	private: System::Windows::Forms::Label^ StorageCostLabel;
	private: System::Windows::Forms::Label^ EvacuationCostHintLabel;

	private: FinesDB::DataBase database_;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->BackBtn = (gcnew System::Windows::Forms::Button());
			this->PlateLabel = (gcnew System::Windows::Forms::Label());
			this->HumanFIOLabel = (gcnew System::Windows::Forms::Label());
			this->PlateInput = (gcnew System::Windows::Forms::ComboBox());
			this->FIOLabel = (gcnew System::Windows::Forms::Label());
			this->ArticleInput = (gcnew System::Windows::Forms::ComboBox());
			this->ArticeLabel = (gcnew System::Windows::Forms::Label());
			this->InterpretationInput = (gcnew System::Windows::Forms::ComboBox());
			this->InterpretationLabel = (gcnew System::Windows::Forms::Label());
			this->NeedEvacuationCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->FineLabel = (gcnew System::Windows::Forms::Label());
			this->FineInput = (gcnew System::Windows::Forms::TextBox());
			this->FineInfoLabel = (gcnew System::Windows::Forms::Label());
			this->PunishmentLabel = (gcnew System::Windows::Forms::Label());
			this->HintLabel = (gcnew System::Windows::Forms::Label());
			this->NextBtn = (gcnew System::Windows::Forms::Button());
			this->StorageCostInput = (gcnew System::Windows::Forms::TextBox());
			this->EvacuationCostInput = (gcnew System::Windows::Forms::TextBox());
			this->EvacuationCostLabel = (gcnew System::Windows::Forms::Label());
			this->StorageCostLabel = (gcnew System::Windows::Forms::Label());
			this->EvacuationCostHintLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// BackBtn
			// 
			this->BackBtn->Location = System::Drawing::Point(12, 272);
			this->BackBtn->Name = L"BackBtn";
			this->BackBtn->Size = System::Drawing::Size(193, 33);
			this->BackBtn->TabIndex = 0;
			this->BackBtn->Text = L"Назад";
			this->BackBtn->UseVisualStyleBackColor = true;
			this->BackBtn->Click += gcnew System::EventHandler(this, &Violations::BackBtn_Click);
			// 
			// PlateLabel
			// 
			this->PlateLabel->AutoSize = true;
			this->PlateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PlateLabel->Location = System::Drawing::Point(29, 33);
			this->PlateLabel->Name = L"PlateLabel";
			this->PlateLabel->Size = System::Drawing::Size(128, 18);
			this->PlateLabel->TabIndex = 2;
			this->PlateLabel->Text = L"Номер машины";
			// 
			// HumanFIOLabel
			// 
			this->HumanFIOLabel->AutoSize = true;
			this->HumanFIOLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HumanFIOLabel->Location = System::Drawing::Point(198, 33);
			this->HumanFIOLabel->Name = L"HumanFIOLabel";
			this->HumanFIOLabel->Size = System::Drawing::Size(126, 18);
			this->HumanFIOLabel->TabIndex = 3;
			this->HumanFIOLabel->Text = L"ФИО водителя";
			// 
			// PlateInput
			// 
			this->PlateInput->Location = System::Drawing::Point(29, 54);
			this->PlateInput->Name = L"PlateInput";
			this->PlateInput->Size = System::Drawing::Size(163, 24);
			this->PlateInput->TabIndex = 0;
			this->PlateInput->TextUpdate += gcnew System::EventHandler(this, &Violations::PlateInput_TextUpdate);
			this->PlateInput->TextChanged += gcnew System::EventHandler(this, &Violations::PlateInput_TextChanged);
			// 
			// FIOLabel
			// 
			this->FIOLabel->AutoSize = true;
			this->FIOLabel->Location = System::Drawing::Point(198, 57);
			this->FIOLabel->Name = L"FIOLabel";
			this->FIOLabel->Size = System::Drawing::Size(181, 16);
			this->FIOLabel->TabIndex = 5;
			this->FIOLabel->Text = L"ФИО водителя не найдено";
			// 
			// ArticleInput
			// 
			this->ArticleInput->Location = System::Drawing::Point(29, 145);
			this->ArticleInput->Name = L"ArticleInput";
			this->ArticleInput->Size = System::Drawing::Size(163, 24);
			this->ArticleInput->TabIndex = 6;
			this->ArticleInput->TextUpdate += gcnew System::EventHandler(this, &Violations::ArticleInput_TextUpdate);
			this->ArticleInput->TextChanged += gcnew System::EventHandler(this, &Violations::ArticleInput_TextChanged);
			// 
			// ArticeLabel
			// 
			this->ArticeLabel->AutoSize = true;
			this->ArticeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ArticeLabel->Location = System::Drawing::Point(29, 124);
			this->ArticeLabel->Name = L"ArticeLabel";
			this->ArticeLabel->Size = System::Drawing::Size(117, 18);
			this->ArticeLabel->TabIndex = 7;
			this->ArticeLabel->Text = L"Номер статьи";
			// 
			// InterpretationInput
			// 
			this->InterpretationInput->Location = System::Drawing::Point(198, 145);
			this->InterpretationInput->Name = L"InterpretationInput";
			this->InterpretationInput->Size = System::Drawing::Size(749, 24);
			this->InterpretationInput->TabIndex = 8;
			this->InterpretationInput->TextUpdate += gcnew System::EventHandler(this, &Violations::InterpretationInput_TextUpdate);
			this->InterpretationInput->TextChanged += gcnew System::EventHandler(this, &Violations::InterpretationInput_TextChanged);
			// 
			// InterpretationLabel
			// 
			this->InterpretationLabel->AutoSize = true;
			this->InterpretationLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InterpretationLabel->Location = System::Drawing::Point(195, 124);
			this->InterpretationLabel->Name = L"InterpretationLabel";
			this->InterpretationLabel->Size = System::Drawing::Size(147, 18);
			this->InterpretationLabel->TabIndex = 9;
			this->InterpretationLabel->Text = L"Трактовка статьи";
			// 
			// NeedEvacuationCheckBox
			// 
			this->NeedEvacuationCheckBox->AutoSize = true;
			this->NeedEvacuationCheckBox->Enabled = false;
			this->NeedEvacuationCheckBox->Location = System::Drawing::Point(670, 119);
			this->NeedEvacuationCheckBox->Name = L"NeedEvacuationCheckBox";
			this->NeedEvacuationCheckBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->NeedEvacuationCheckBox->Size = System::Drawing::Size(273, 20);
			this->NeedEvacuationCheckBox->TabIndex = 10;
			this->NeedEvacuationCheckBox->Text = L"Требуется ли эвакуация автомобиля";
			this->NeedEvacuationCheckBox->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->NeedEvacuationCheckBox->UseVisualStyleBackColor = true;
			this->NeedEvacuationCheckBox->CheckedChanged += gcnew System::EventHandler(this, &Violations::NeedEvacuationCheckBox_CheckedChanged);
			// 
			// FineLabel
			// 
			this->FineLabel->AutoSize = true;
			this->FineLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FineLabel->Location = System::Drawing::Point(29, 174);
			this->FineLabel->Name = L"FineLabel";
			this->FineLabel->Size = System::Drawing::Size(62, 18);
			this->FineLabel->TabIndex = 11;
			this->FineLabel->Text = L"Штраф";
			// 
			// FineInput
			// 
			this->FineInput->Location = System::Drawing::Point(29, 194);
			this->FineInput->Name = L"FineInput";
			this->FineInput->Size = System::Drawing::Size(163, 22);
			this->FineInput->TabIndex = 12;
			this->FineInput->Text = L"0";
			// 
			// FineInfoLabel
			// 
			this->FineInfoLabel->AutoSize = true;
			this->FineInfoLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->FineInfoLabel->Location = System::Drawing::Point(26, 220);
			this->FineInfoLabel->Name = L"FineInfoLabel";
			this->FineInfoLabel->Size = System::Drawing::Size(162, 32);
			this->FineInfoLabel->TabIndex = 14;
			this->FineInfoLabel->Text = L"Введите число\nбез пробелов и валюты\n";
			// 
			// PunishmentLabel
			// 
			this->PunishmentLabel->AutoSize = true;
			this->PunishmentLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PunishmentLabel->Location = System::Drawing::Point(195, 174);
			this->PunishmentLabel->Name = L"PunishmentLabel";
			this->PunishmentLabel->Size = System::Drawing::Size(236, 18);
			this->PunishmentLabel->TabIndex = 15;
			this->PunishmentLabel->Text = L"Предусмотренное наказание";
			// 
			// HintLabel
			// 
			this->HintLabel->AutoSize = true;
			this->HintLabel->Location = System::Drawing::Point(198, 200);
			this->HintLabel->Name = L"HintLabel";
			this->HintLabel->Size = System::Drawing::Size(229, 16);
			this->HintLabel->TabIndex = 16;
			this->HintLabel->Text = L"Укажите статью или ее трактовку";
			// 
			// NextBtn
			// 
			this->NextBtn->Enabled = false;
			this->NextBtn->Location = System::Drawing::Point(766, 272);
			this->NextBtn->Name = L"NextBtn";
			this->NextBtn->Size = System::Drawing::Size(193, 33);
			this->NextBtn->TabIndex = 17;
			this->NextBtn->Text = L"Зарегистрировать";
			this->NextBtn->UseVisualStyleBackColor = true;
			this->NextBtn->Click += gcnew System::EventHandler(this, &Violations::NextBtn_Click);
			// 
			// StorageCostInput
			// 
			this->StorageCostInput->Location = System::Drawing::Point(780, 90);
			this->StorageCostInput->Name = L"StorageCostInput";
			this->StorageCostInput->Size = System::Drawing::Size(163, 22);
			this->StorageCostInput->TabIndex = 18;
			this->StorageCostInput->Text = L"0";
			this->StorageCostInput->Visible = false;
			this->StorageCostInput->TextChanged += gcnew System::EventHandler(this, &Violations::StorageCostInput_TextChanged);
			// 
			// EvacuationCostInput
			// 
			this->EvacuationCostInput->Location = System::Drawing::Point(780, 60);
			this->EvacuationCostInput->Name = L"EvacuationCostInput";
			this->EvacuationCostInput->Size = System::Drawing::Size(163, 22);
			this->EvacuationCostInput->TabIndex = 19;
			this->EvacuationCostInput->Text = L"0";
			this->EvacuationCostInput->Visible = false;
			this->EvacuationCostInput->TextChanged += gcnew System::EventHandler(this, &Violations::EvacuationCostInput_TextChanged);
			// 
			// EvacuationCostLabel
			// 
			this->EvacuationCostLabel->AutoSize = true;
			this->EvacuationCostLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EvacuationCostLabel->Location = System::Drawing::Point(557, 61);
			this->EvacuationCostLabel->Name = L"EvacuationCostLabel";
			this->EvacuationCostLabel->Size = System::Drawing::Size(180, 18);
			this->EvacuationCostLabel->TabIndex = 20;
			this->EvacuationCostLabel->Text = L"Стоимость эвакуации";
			this->EvacuationCostLabel->Visible = false;
			// 
			// StorageCostLabel
			// 
			this->StorageCostLabel->AutoSize = true;
			this->StorageCostLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StorageCostLabel->Location = System::Drawing::Point(574, 91);
			this->StorageCostLabel->Name = L"StorageCostLabel";
			this->StorageCostLabel->Size = System::Drawing::Size(163, 18);
			this->StorageCostLabel->TabIndex = 21;
			this->StorageCostLabel->Text = L"Стоимость стоянки";
			this->StorageCostLabel->Visible = false;
			// 
			// EvacuationCostHintLabel
			// 
			this->EvacuationCostHintLabel->AutoSize = true;
			this->EvacuationCostHintLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->EvacuationCostHintLabel->Location = System::Drawing::Point(781, 19);
			this->EvacuationCostHintLabel->Name = L"EvacuationCostHintLabel";
			this->EvacuationCostHintLabel->Size = System::Drawing::Size(162, 32);
			this->EvacuationCostHintLabel->TabIndex = 22;
			this->EvacuationCostHintLabel->Text = L"Введите стоимости\nбез пробелов и валюты\n";
			this->EvacuationCostHintLabel->Visible = false;
			// 
			// Violations
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(973, 317);
			this->Controls->Add(this->EvacuationCostHintLabel);
			this->Controls->Add(this->StorageCostLabel);
			this->Controls->Add(this->EvacuationCostLabel);
			this->Controls->Add(this->EvacuationCostInput);
			this->Controls->Add(this->StorageCostInput);
			this->Controls->Add(this->NextBtn);
			this->Controls->Add(this->HintLabel);
			this->Controls->Add(this->PunishmentLabel);
			this->Controls->Add(this->FineInfoLabel);
			this->Controls->Add(this->FineInput);
			this->Controls->Add(this->FineLabel);
			this->Controls->Add(this->NeedEvacuationCheckBox);
			this->Controls->Add(this->InterpretationInput);
			this->Controls->Add(this->InterpretationLabel);
			this->Controls->Add(this->ArticleInput);
			this->Controls->Add(this->ArticeLabel);
			this->Controls->Add(this->FIOLabel);
			this->Controls->Add(this->PlateInput);
			this->Controls->Add(this->HumanFIOLabel);
			this->Controls->Add(this->PlateLabel);
			this->Controls->Add(this->BackBtn);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Violations";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Регистрация нарушения";
			this->ResumeLayout(false);
			this->PerformLayout();
		}

		void InitalizeAddingComponets() {
			PlateInput->Items->AddRange(database_.GetTableData(commands::PLATE));
			ArticleInput->Items->AddRange(database_.GetTableData(commands::ARTICLE));
			InterpretationInput->Items->AddRange(database_.GetTableData(commands::INTER));
		}
#pragma endregion
	private: bool IsSomethingFilled() {
		return !String::IsNullOrEmpty(InterpretationInput->Text) || !String::IsNullOrEmpty(PlateInput->Text) || !String::IsNullOrEmpty(ArticleInput->Text) || (!String::IsNullOrEmpty(FineInput->Text) && FineInput->Text != "0") || ((!String::IsNullOrEmpty(EvacuationCostInput->Text) || !String::IsNullOrEmpty(StorageCostInput->Text)) && (EvacuationCostInput->Text != "0" || StorageCostInput->Text != "0"));
	}
	private: System::Void BackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (IsSomethingFilled()) {
			System::Windows::Forms::DialogResult result = MessageBox::Show("Данные которые вы ввели не будут сохранены.\nВы уверены, что хотите продолжить?", "Подтверждение", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);

			if (result == System::Windows::Forms::DialogResult::No) {
				return;
			}
		}
		this->Close();
	}

	private: bool IsAllFilled() {
		if (!String::IsNullOrEmpty(InterpretationInput->Text) && !String::IsNullOrEmpty(PlateInput->Text) && !String::IsNullOrEmpty(ArticleInput->Text) && !String::IsNullOrEmpty(FineInput->Text)) {
			if (NeedEvacuationCheckBox->Checked) {
				if (!String::IsNullOrEmpty(EvacuationCostInput->Text) && !String::IsNullOrEmpty(StorageCostInput->Text) && EvacuationCostInput->Text != "0" && StorageCostInput->Text != "0") {
					return true;
				}
			}
			else return true;
		}
		return false;
	}
	private: System::Void NextBtn_Cheker() {
		if (IsAllFilled()) {
			NextBtn->Enabled = true;
		}
		else {
			NextBtn->Enabled = false;
		}
	}
	private: System::Void Evacuation_Cheker() {
		if (NeedEvacuationCheckBox->Checked) {
			EvacuationCostHintLabel->Visible = true;

			EvacuationCostLabel->Visible = true;
			StorageCostLabel->Visible = true;

			EvacuationCostInput->Visible = true;
			StorageCostInput->Visible = true;
		}
		else {
			EvacuationCostHintLabel->Visible = false;

			EvacuationCostLabel->Visible = false;
			StorageCostLabel->Visible = false;
			
			EvacuationCostInput->Visible = false;
			StorageCostInput->Visible = false;
		}
	}
	private: System::Void NeedEvacuationCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Evacuation_Cheker();
		NextBtn_Cheker();
	}
	private: System::Void NextBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		domain::ViolationInfo^ violation = GenerateViolationInsertData();

		if (violation != nullptr) {
			database_.InsertViolation(violation);

			if (violation->is_evacuated) {
				database_.InsertEvacuation(GenerateEvacuationInsertData(violation->violation_id));
			}

			MessageBox::Show("Регистрация прошла успешно!", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
	}
	//
	private: System::Void PlateInput_TextUpdate(System::Object^ sender, System::EventArgs^ e) {
		int selectionStart = PlateInput->SelectionStart;
		PlateInput->DroppedDown = true;

		String^ userInput = PlateInput->Text->ToUpper();
		PlateInput->Items->Clear();

		for each (String ^ plateNumber in database_.GetTableData(commands::PLATE)) {
			if (plateNumber->StartsWith(userInput)) {
				PlateInput->Items->Add(plateNumber);
			}
		}
		PlateInput->SelectionStart = selectionStart;
		NextBtn_Cheker();
	}
	private: System::Void PlateInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		FIOLabel->Text = database_.FindDriverByPlate(PlateInput->Text);
		NextBtn_Cheker();
	}
	//
	private: System::Void ArticleInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		domain::FineInfo^ fine_info = database_.FindFineInfo(commands::ARTICLE, ArticleInput->Text);

		InterpretationInput->Text = fine_info->fine_name;
		HintLabel->Text = fine_info->punishment;

		if (fine_info->need_evacuation != nullptr) {
			if (*fine_info->need_evacuation == 1) {
				NeedEvacuationCheckBox->Checked = true;
				NeedEvacuationCheckBox->Enabled = false;
			}
			else if (*fine_info->need_evacuation == 0) {
				NeedEvacuationCheckBox->Checked = false;
				NeedEvacuationCheckBox->Enabled = false;
			}
		}
		else {
			NeedEvacuationCheckBox->Enabled = true;
		}
		NextBtn_Cheker();
		Evacuation_Cheker();
	}
	private: System::Void ArticleInput_TextUpdate(System::Object^ sender, System::EventArgs^ e) {
		int selectionStart = ArticleInput->SelectionStart;
		ArticleInput->DroppedDown = true;

		String^ userInput = ArticleInput->Text->ToUpper();
		ArticleInput->Items->Clear();

		for each (String ^ data in database_.GetTableData(commands::ARTICLE)) {
			if (data->StartsWith(userInput)) {
				ArticleInput->Items->Add(data);
			}
		}
		ArticleInput->SelectionStart = selectionStart;
	}
	//
	private: System::Void InterpretationInput_TextUpdate(System::Object^ sender, System::EventArgs^ e) {
		int selectionStart = InterpretationInput->SelectionStart;
		InterpretationInput->DroppedDown = true;

		String^ userInput = InterpretationInput->Text;
		InterpretationInput->Items->Clear();

		for each (String ^ data in database_.GetTableData(commands::INTER)) {
			if (data->StartsWith(userInput)) {
				InterpretationInput->Items->Add(data);
			}
		}
		InterpretationInput->SelectionStart = selectionStart;
	}
	private: System::Void InterpretationInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		domain::FineInfo^ fine_info = database_.FindFineInfo(commands::INTER, InterpretationInput->Text);

		ArticleInput->Text = fine_info->article;
		HintLabel->Text = fine_info->punishment;

		if (fine_info->need_evacuation != nullptr) {
			if (*fine_info->need_evacuation == 1) {
				NeedEvacuationCheckBox->Checked = true;
				NeedEvacuationCheckBox->Enabled = false;
			}
			else if (*fine_info->need_evacuation == 0) {
				NeedEvacuationCheckBox->Checked = false;
				NeedEvacuationCheckBox->Enabled = false;
			}
		}
		else {
			NeedEvacuationCheckBox->Enabled = true;
		}
		NextBtn_Cheker();
		Evacuation_Cheker();
	}

	private: domain::ViolationInfo^ GenerateViolationInsertData() {
		domain::ViolationInfo^ violation = gcnew domain::ViolationInfo();

		int fineCost;
		if (Int32::TryParse(FineInput->Text, fineCost)) {
			violation->fine_cost = fineCost;
		}
		else {
			MessageBox::Show("Неверный формат ввода для штрафа!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return nullptr;
		}

		//эвакуация пошла по пизде
		violation->is_evacuated = NeedEvacuationCheckBox->Checked;
		String^ plate = PlateInput->Text;
		String^ article = ArticleInput->Text;
		
		violation->driver_id = database_.FindId(commands::PLATE, plate);
		violation->fine_id = database_.FindId(commands::ARTICLE, article);
		return violation;
	}
	private: domain::EvacuationInfo^ GenerateEvacuationInsertData(int violation_id) {
		domain::EvacuationInfo^ evacuation = gcnew domain::EvacuationInfo();

		int evacuation_cost;
		int storage_cost;
		if (Int32::TryParse(EvacuationCostInput->Text, evacuation_cost) && Int32::TryParse(StorageCostInput->Text, storage_cost)) {
			evacuation->evacuation_cost = evacuation_cost;
			evacuation->storage_cost = storage_cost;
		}
		else {
			MessageBox::Show("Неверный формат ввода для стоимости эвакуации или стоянки!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return nullptr;
		}


		String^ plate = PlateInput->Text;
		evacuation->driver_id = database_.FindId(commands::PLATE, plate);
		evacuation->violation_id = violation_id;
		return evacuation;
	}

	private: System::Void EvacuationCostInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		NextBtn_Cheker();
		Evacuation_Cheker();
	}
	private: System::Void StorageCostInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		NextBtn_Cheker();
		Evacuation_Cheker();
	}
};
}
