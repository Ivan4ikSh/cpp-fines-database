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
	/// Сводка для UserGUI
	/// </summary>
	public ref class UserGUI : public System::Windows::Forms::Form
	{
	public:
		UserGUI(void)
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
		~UserGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ FIOLabel;
	protected:

	private: System::Windows::Forms::Label^ HumanFIOLabel;
	private: System::Windows::Forms::Label^ PlateLabel;
	private: System::Windows::Forms::TextBox^ PlateInput;
	private: System::Windows::Forms::DataGridView^ PaymentsGridView;
	private: System::Windows::Forms::Button^ PayBtn;

	private: FinesDB::DataBase database_;
	private: System::Windows::Forms::Button^ SearchBtn;


	private: System::Windows::Forms::Button^ NotificationBtn;
	private: System::Windows::Forms::ListBox^ NotificationList;
	private: System::Windows::Forms::PictureBox^ NotifyPB;



	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserGUI::typeid));
			this->FIOLabel = (gcnew System::Windows::Forms::Label());
			this->HumanFIOLabel = (gcnew System::Windows::Forms::Label());
			this->PlateLabel = (gcnew System::Windows::Forms::Label());
			this->PlateInput = (gcnew System::Windows::Forms::TextBox());
			this->PaymentsGridView = (gcnew System::Windows::Forms::DataGridView());
			this->PayBtn = (gcnew System::Windows::Forms::Button());
			this->SearchBtn = (gcnew System::Windows::Forms::Button());
			this->NotificationBtn = (gcnew System::Windows::Forms::Button());
			this->NotificationList = (gcnew System::Windows::Forms::ListBox());
			this->NotifyPB = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PaymentsGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NotifyPB))->BeginInit();
			this->SuspendLayout();
			// 
			// FIOLabel
			// 
			this->FIOLabel->AutoSize = true;
			this->FIOLabel->Location = System::Drawing::Point(286, 33);
			this->FIOLabel->Name = L"FIOLabel";
			this->FIOLabel->Size = System::Drawing::Size(189, 16);
			this->FIOLabel->TabIndex = 9;
			this->FIOLabel->Text = L"Введите номер автомобиля";
			// 
			// HumanFIOLabel
			// 
			this->HumanFIOLabel->AutoSize = true;
			this->HumanFIOLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HumanFIOLabel->Location = System::Drawing::Point(286, 9);
			this->HumanFIOLabel->Name = L"HumanFIOLabel";
			this->HumanFIOLabel->Size = System::Drawing::Size(126, 18);
			this->HumanFIOLabel->TabIndex = 8;
			this->HumanFIOLabel->Text = L"ФИО водителя";
			// 
			// PlateLabel
			// 
			this->PlateLabel->AutoSize = true;
			this->PlateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PlateLabel->Location = System::Drawing::Point(12, 9);
			this->PlateLabel->Name = L"PlateLabel";
			this->PlateLabel->Size = System::Drawing::Size(128, 18);
			this->PlateLabel->TabIndex = 7;
			this->PlateLabel->Text = L"Номер машины";
			// 
			// PlateInput
			// 
			this->PlateInput->Location = System::Drawing::Point(15, 30);
			this->PlateInput->Name = L"PlateInput";
			this->PlateInput->Size = System::Drawing::Size(163, 22);
			this->PlateInput->TabIndex = 10;
			this->PlateInput->TextChanged += gcnew System::EventHandler(this, &UserGUI::PlateInput_TextChanged);
			this->PlateInput->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UserGUI::PlateInput_KeyDown);
			// 
			// PaymentsGridView
			// 
			this->PaymentsGridView->AllowUserToAddRows = false;
			this->PaymentsGridView->AllowUserToDeleteRows = false;
			this->PaymentsGridView->AllowUserToResizeColumns = false;
			this->PaymentsGridView->AllowUserToResizeRows = false;
			this->PaymentsGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->PaymentsGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->PaymentsGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->PaymentsGridView->DefaultCellStyle = dataGridViewCellStyle1;
			this->PaymentsGridView->Location = System::Drawing::Point(15, 59);
			this->PaymentsGridView->MultiSelect = false;
			this->PaymentsGridView->Name = L"PaymentsGridView";
			this->PaymentsGridView->ReadOnly = true;
			this->PaymentsGridView->RowHeadersWidth = 51;
			this->PaymentsGridView->RowTemplate->Height = 24;
			this->PaymentsGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->PaymentsGridView->Size = System::Drawing::Size(853, 374);
			this->PaymentsGridView->TabIndex = 13;
			this->PaymentsGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UserGUI::PaymentsGridView_CellContentClick);
			// 
			// PayBtn
			// 
			this->PayBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PayBtn->Enabled = false;
			this->PayBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PayBtn->Location = System::Drawing::Point(373, 439);
			this->PayBtn->Name = L"PayBtn";
			this->PayBtn->Size = System::Drawing::Size(167, 45);
			this->PayBtn->TabIndex = 15;
			this->PayBtn->Text = L"Оплатить";
			this->PayBtn->UseVisualStyleBackColor = true;
			this->PayBtn->Click += gcnew System::EventHandler(this, &UserGUI::PayBtn_Click);
			// 
			// SearchBtn
			// 
			this->SearchBtn->Location = System::Drawing::Point(184, 30);
			this->SearchBtn->Name = L"SearchBtn";
			this->SearchBtn->Size = System::Drawing::Size(84, 23);
			this->SearchBtn->TabIndex = 16;
			this->SearchBtn->Text = L"Поиск";
			this->SearchBtn->UseVisualStyleBackColor = true;
			this->SearchBtn->Click += gcnew System::EventHandler(this, &UserGUI::SearchBtn_Click);
			// 
			// NotificationBtn
			// 
			this->NotificationBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->NotificationBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"NotificationBtn.BackgroundImage")));
			this->NotificationBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->NotificationBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->NotificationBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->NotificationBtn->ForeColor = System::Drawing::Color::Transparent;
			this->NotificationBtn->Location = System::Drawing::Point(812, 13);
			this->NotificationBtn->Name = L"NotificationBtn";
			this->NotificationBtn->Size = System::Drawing::Size(40, 40);
			this->NotificationBtn->TabIndex = 20;
			this->NotificationBtn->UseVisualStyleBackColor = false;
			this->NotificationBtn->Visible = false;
			this->NotificationBtn->Click += gcnew System::EventHandler(this, &UserGUI::NotificationBtn_Click);
			// 
			// NotificationList
			// 
			this->NotificationList->FormattingEnabled = true;
			this->NotificationList->ItemHeight = 16;
			this->NotificationList->Location = System::Drawing::Point(246, 59);
			this->NotificationList->Name = L"NotificationList";
			this->NotificationList->Size = System::Drawing::Size(622, 372);
			this->NotificationList->TabIndex = 21;
			this->NotificationList->Visible = false;
			// 
			// NotifyPB
			// 
			this->NotifyPB->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"NotifyPB.BackgroundImage")));
			this->NotifyPB->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->NotifyPB->Location = System::Drawing::Point(797, 13);
			this->NotifyPB->Name = L"NotifyPB";
			this->NotifyPB->Size = System::Drawing::Size(15, 15);
			this->NotifyPB->TabIndex = 22;
			this->NotifyPB->TabStop = false;
			this->NotifyPB->Visible = false;
			// 
			// UserGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(880, 496);
			this->Controls->Add(this->NotifyPB);
			this->Controls->Add(this->NotificationList);
			this->Controls->Add(this->NotificationBtn);
			this->Controls->Add(this->SearchBtn);
			this->Controls->Add(this->PayBtn);
			this->Controls->Add(this->PaymentsGridView);
			this->Controls->Add(this->PlateInput);
			this->Controls->Add(this->FIOLabel);
			this->Controls->Add(this->HumanFIOLabel);
			this->Controls->Add(this->PlateLabel);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"UserGUI";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Оплата ГАИ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PaymentsGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NotifyPB))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void InitalizeAddingComponets() {
			PlateInput->ResetText();
			PaymentsGridView->DefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Bold);
			PaymentsGridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);

			PaymentsGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			PaymentsGridView->ClearSelection();

			NotificationBtn->FlatAppearance->MouseOverBackColor = NotificationBtn->BackColor;
		}
#pragma endregion
	private: System::Void PlateInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		FIOLabel->Text = database_.FindDriverByPlate(PlateInput->Text);
	}
	private: System::Void SearchBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!String::IsNullOrEmpty(PlateInput->Text)) {
			PaymentsGridView->DataSource = database_.UpdatePaymentsForUser(PlateInput->Text);
			PaymentsGridView->Columns["type_id"]->Visible = false;

			NotificationBtn->Visible = true;
			InitializeNotifications(PlateInput->Text);

			if (NotificationList->Items->Count > 1) {
				NotifyPB->Visible = true;
			}
			else {
				NotifyPB->Visible = false;
			}
		}
		else {
			PaymentsGridView->DataSource = nullptr;

			NotificationBtn->Visible = false;
			NotifyPB->Visible = false;
			NotificationList->Visible = false;
		}
	}
	private: System::Void PaymentsGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		PayBtn->Enabled = true;
	}
	private: System::Void PayBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PaymentsGridView->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = PaymentsGridView->SelectedRows[0];
			domain::PaymentInfo^ payment_info = gcnew domain::PaymentInfo();

			payment_info->driver_id = database_.FindId(commands::PLATE, PlateInput->Text);
			payment_info->type_id = Convert::ToInt32(selectedRow->Cells["type_id"]->Value);
			payment_info->amount_paid = Convert::ToInt32(selectedRow->Cells["Сумма к оплате"]->Value);

			String^ type = selectedRow->Cells["Тип платежа"]->Value->ToString();

			if (type == "Штраф") {
				database_.InsertPayment(commands::FINE, payment_info);
				database_.UpdateEvacuationeReturnDate(payment_info->type_id);
			}
			if (type == "Эвакуация") {
				database_.InsertPayment(commands::EVACUATION, payment_info);
			}

			MessageBox::Show("Оплата прошла успешно!", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
			//InitalizeAddingComponets();
			PaymentsGridView->DataSource = database_.UpdatePaymentsForUser(PlateInput->Text);
			PaymentsGridView->Columns["type_id"]->Visible = false;
		}
	}
	private: System::Void NotificationBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		NotificationList->Visible = (NotificationList->Visible) ? false : true;
	}

	private: System::Void InitializeNotifications(String^ plate) {
		NotificationList->Items->AddRange(database_.GetNotificationsByPlate(plate));
	}
	//
	private: System::Void PlateInput_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			SearchBtn_Click(sender, e);
		}
	}
};
}
 //a123bd45