#pragma once

namespace FinesDatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Payments
	/// </summary>
	public ref class Payments : public System::Windows::Forms::Form
	{
	public:
		Payments(void)
		{
			InitializeComponent();
			InitalizeAddingComponets();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Payments()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ PlateInput;
	private: System::Windows::Forms::DataGridView^ PaymentsGridView;
	private: System::Windows::Forms::Label^ FIOLabel;
	private: System::Windows::Forms::Label^ HumanFIOLabel;
	private: System::Windows::Forms::Label^ PlateLabel;
	private: System::Windows::Forms::Label^ RefreshLabel;
	private: System::Windows::Forms::Button^ BackBtn;
	private: System::Windows::Forms::Button^ RefreshBtn;

	private: FinesDB::DataBase database_;
	private: System::Windows::Forms::RadioButton^ FineRadioBtn;
	private: System::Windows::Forms::RadioButton^ EvacuationRadioBtn;


	private: System::Windows::Forms::Label^ PaymentTypeLabel;


	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Payments::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->BackBtn = (gcnew System::Windows::Forms::Button());
			this->FIOLabel = (gcnew System::Windows::Forms::Label());
			this->PlateInput = (gcnew System::Windows::Forms::ComboBox());
			this->HumanFIOLabel = (gcnew System::Windows::Forms::Label());
			this->PlateLabel = (gcnew System::Windows::Forms::Label());
			this->RefreshBtn = (gcnew System::Windows::Forms::Button());
			this->RefreshLabel = (gcnew System::Windows::Forms::Label());
			this->PaymentsGridView = (gcnew System::Windows::Forms::DataGridView());
			this->FineRadioBtn = (gcnew System::Windows::Forms::RadioButton());
			this->EvacuationRadioBtn = (gcnew System::Windows::Forms::RadioButton());
			this->PaymentTypeLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PaymentsGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// BackBtn
			// 
			this->BackBtn->Location = System::Drawing::Point(33, 536);
			this->BackBtn->Name = L"BackBtn";
			this->BackBtn->Size = System::Drawing::Size(193, 33);
			this->BackBtn->TabIndex = 0;
			this->BackBtn->Text = L"Назад";
			this->BackBtn->UseVisualStyleBackColor = true;
			this->BackBtn->Click += gcnew System::EventHandler(this, &Payments::BackBtn_Click);
			// 
			// FIOLabel
			// 
			this->FIOLabel->AutoSize = true;
			this->FIOLabel->Location = System::Drawing::Point(243, 57);
			this->FIOLabel->Name = L"FIOLabel";
			this->FIOLabel->Size = System::Drawing::Size(181, 16);
			this->FIOLabel->TabIndex = 9;
			this->FIOLabel->Text = L"ФИО водителя не найдено";
			// 
			// PlateInput
			// 
			this->PlateInput->Location = System::Drawing::Point(33, 54);
			this->PlateInput->Name = L"PlateInput";
			this->PlateInput->Size = System::Drawing::Size(163, 24);
			this->PlateInput->TabIndex = 6;
			this->PlateInput->TextUpdate += gcnew System::EventHandler(this, &Payments::PlateInput_TextUpdate);
			this->PlateInput->TextChanged += gcnew System::EventHandler(this, &Payments::PlateInput_TextChanged);
			// 
			// HumanFIOLabel
			// 
			this->HumanFIOLabel->AutoSize = true;
			this->HumanFIOLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HumanFIOLabel->Location = System::Drawing::Point(243, 33);
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
			this->PlateLabel->Location = System::Drawing::Point(33, 33);
			this->PlateLabel->Name = L"PlateLabel";
			this->PlateLabel->Size = System::Drawing::Size(128, 18);
			this->PlateLabel->TabIndex = 7;
			this->PlateLabel->Text = L"Номер машины";
			// 
			// RefreshBtn
			// 
			this->RefreshBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RefreshBtn.BackgroundImage")));
			this->RefreshBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->RefreshBtn->Location = System::Drawing::Point(1307, 45);
			this->RefreshBtn->Name = L"RefreshBtn";
			this->RefreshBtn->Size = System::Drawing::Size(40, 40);
			this->RefreshBtn->TabIndex = 11;
			this->RefreshBtn->UseVisualStyleBackColor = true;
			this->RefreshBtn->Click += gcnew System::EventHandler(this, &Payments::RefreshBtn_Click);
			// 
			// RefreshLabel
			// 
			this->RefreshLabel->AutoSize = true;
			this->RefreshLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RefreshLabel->Location = System::Drawing::Point(1207, 54);
			this->RefreshLabel->Name = L"RefreshLabel";
			this->RefreshLabel->Size = System::Drawing::Size(85, 18);
			this->RefreshLabel->TabIndex = 12;
			this->RefreshLabel->Text = L"Обновить";
			// 
			// PaymentsGridView
			// 
			this->PaymentsGridView->AllowUserToAddRows = false;
			this->PaymentsGridView->AllowUserToDeleteRows = false;
			this->PaymentsGridView->AllowUserToOrderColumns = true;
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
			this->PaymentsGridView->Location = System::Drawing::Point(12, 96);
			this->PaymentsGridView->MultiSelect = false;
			this->PaymentsGridView->Name = L"PaymentsGridView";
			this->PaymentsGridView->ReadOnly = true;
			this->PaymentsGridView->RowHeadersWidth = 51;
			this->PaymentsGridView->RowTemplate->Height = 24;
			this->PaymentsGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->PaymentsGridView->Size = System::Drawing::Size(1335, 424);
			this->PaymentsGridView->TabIndex = 13;
			// 
			// FineRadioBtn
			// 
			this->FineRadioBtn->AutoSize = true;
			this->FineRadioBtn->Location = System::Drawing::Point(994, 31);
			this->FineRadioBtn->Name = L"FineRadioBtn";
			this->FineRadioBtn->Size = System::Drawing::Size(73, 20);
			this->FineRadioBtn->TabIndex = 14;
			this->FineRadioBtn->TabStop = true;
			this->FineRadioBtn->Text = L"Штраф";
			this->FineRadioBtn->UseVisualStyleBackColor = true;
			this->FineRadioBtn->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Payments::FineRadioBtn_MouseClick);
			// 
			// EvacuationRadioBtn
			// 
			this->EvacuationRadioBtn->AutoSize = true;
			this->EvacuationRadioBtn->Location = System::Drawing::Point(994, 57);
			this->EvacuationRadioBtn->Name = L"EvacuationRadioBtn";
			this->EvacuationRadioBtn->Size = System::Drawing::Size(100, 20);
			this->EvacuationRadioBtn->TabIndex = 15;
			this->EvacuationRadioBtn->TabStop = true;
			this->EvacuationRadioBtn->Text = L"Эвакуация";
			this->EvacuationRadioBtn->UseVisualStyleBackColor = true;
			this->EvacuationRadioBtn->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Payments::EvacuationRadioBtn_MouseClick);
			// 
			// PaymentTypeLabel
			// 
			this->PaymentTypeLabel->AutoSize = true;
			this->PaymentTypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PaymentTypeLabel->Location = System::Drawing::Point(873, 46);
			this->PaymentTypeLabel->Name = L"PaymentTypeLabel";
			this->PaymentTypeLabel->Size = System::Drawing::Size(99, 18);
			this->PaymentTypeLabel->TabIndex = 16;
			this->PaymentTypeLabel->Text = L"Тип оплаты";
			// 
			// Payments
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1359, 594);
			this->Controls->Add(this->PaymentTypeLabel);
			this->Controls->Add(this->EvacuationRadioBtn);
			this->Controls->Add(this->FineRadioBtn);
			this->Controls->Add(this->PaymentsGridView);
			this->Controls->Add(this->RefreshLabel);
			this->Controls->Add(this->RefreshBtn);
			this->Controls->Add(this->FIOLabel);
			this->Controls->Add(this->PlateInput);
			this->Controls->Add(this->HumanFIOLabel);
			this->Controls->Add(this->PlateLabel);
			this->Controls->Add(this->BackBtn);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Payments";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Архив данных о штрафах";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PaymentsGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitalizeAddingComponets() {
			PlateInput->ResetText();
			FIOLabel->Text = L"ФИО водителя не найдено";

			PlateInput->Items->AddRange(database_.GetTableData(commands::PLATE));
			FineRadioBtn->Checked = false;
			EvacuationRadioBtn->Checked = false;

			PaymentsGridView->DataSource = database_.UpdatePaymentsTable(commands::ALL, nullptr);

			PaymentsGridView->DefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Bold);
			PaymentsGridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
			
			PaymentsGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			PaymentsGridView->ClearSelection();
		}
#pragma endregion
	private: System::Void BackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void RefreshBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		InitalizeAddingComponets();
	}
	//--
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
	}
	private: System::Void PlateInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		FIOLabel->Text = database_.FindDriverByPlate(PlateInput->Text);

		if (String::IsNullOrEmpty(PlateInput->Text)) {
			PaymentsGridView->DataSource = database_.UpdatePaymentsTable(commands::ALL, nullptr);
		}
		else {
			PaymentsGridView->DataSource = database_.UpdatePaymentsTable(commands::PLATE, PlateInput->Text);
		}
	}
	private: System::Void FineRadioBtn_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (String::IsNullOrEmpty(PlateInput->Text)) {
			PaymentsGridView->DataSource = database_.UpdatePaymentsTable(commands::FINE, nullptr);
		}
		else {
			PaymentsGridView->DataSource = database_.UpdatePaymentsTable(commands::FINE, PlateInput->Text);
		}		
	}
	private: System::Void EvacuationRadioBtn_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (String::IsNullOrEmpty(PlateInput->Text)) {
			PaymentsGridView->DataSource = database_.UpdatePaymentsTable(commands::EVACUATION, nullptr);
		}
		else {
			PaymentsGridView->DataSource = database_.UpdatePaymentsTable(commands::EVACUATION, PlateInput->Text);
		}
	}
};
}
