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
	/// Сводка для stats
	/// </summary>
	public ref class Stats : public System::Windows::Forms::Form
	{
	public:
		Stats(void)
		{
			InitializeComponent();
			InitializeAddingComponents();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Stats()
		{
			if (components)
			{
				delete components;
			}
		}
	private: FinesDB::DataBase database_;

	private: System::Windows::Forms::Button^ BackBtn;
	private: System::Windows::Forms::Label^ RefreshLabel;
	private: System::Windows::Forms::Button^ RefreshBtn;
	private: System::Windows::Forms::DataGridView^ ProfitGridView;

	private: System::Windows::Forms::Label^ ProfitLabel;
	private: System::Windows::Forms::DataGridView^ MostLawersGridView;
	private: System::Windows::Forms::DataGridView^ MostFinersGridView;



	private: System::Windows::Forms::Label^ MostLawersLabel;
	private: System::Windows::Forms::Label^ MostFinersLabel;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stats::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->BackBtn = (gcnew System::Windows::Forms::Button());
			this->RefreshLabel = (gcnew System::Windows::Forms::Label());
			this->RefreshBtn = (gcnew System::Windows::Forms::Button());
			this->ProfitGridView = (gcnew System::Windows::Forms::DataGridView());
			this->ProfitLabel = (gcnew System::Windows::Forms::Label());
			this->MostLawersGridView = (gcnew System::Windows::Forms::DataGridView());
			this->MostFinersGridView = (gcnew System::Windows::Forms::DataGridView());
			this->MostLawersLabel = (gcnew System::Windows::Forms::Label());
			this->MostFinersLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProfitGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MostLawersGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MostFinersGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// BackBtn
			// 
			this->BackBtn->Location = System::Drawing::Point(12, 579);
			this->BackBtn->Name = L"BackBtn";
			this->BackBtn->Size = System::Drawing::Size(193, 33);
			this->BackBtn->TabIndex = 1;
			this->BackBtn->Text = L"Назад";
			this->BackBtn->UseVisualStyleBackColor = true;
			this->BackBtn->Click += gcnew System::EventHandler(this, &Stats::BackBtn_Click);
			// 
			// RefreshLabel
			// 
			this->RefreshLabel->AutoSize = true;
			this->RefreshLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RefreshLabel->Location = System::Drawing::Point(604, 8);
			this->RefreshLabel->Name = L"RefreshLabel";
			this->RefreshLabel->Size = System::Drawing::Size(85, 18);
			this->RefreshLabel->TabIndex = 14;
			this->RefreshLabel->Text = L"Обновить";
			// 
			// RefreshBtn
			// 
			this->RefreshBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RefreshBtn.BackgroundImage")));
			this->RefreshBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->RefreshBtn->Location = System::Drawing::Point(698, 5);
			this->RefreshBtn->Name = L"RefreshBtn";
			this->RefreshBtn->Size = System::Drawing::Size(25, 25);
			this->RefreshBtn->TabIndex = 13;
			this->RefreshBtn->UseVisualStyleBackColor = true;
			this->RefreshBtn->Click += gcnew System::EventHandler(this, &Stats::RefreshBtn_Click);
			// 
			// ProfitGridView
			// 
			this->ProfitGridView->AllowUserToAddRows = false;
			this->ProfitGridView->AllowUserToDeleteRows = false;
			this->ProfitGridView->AllowUserToResizeColumns = false;
			this->ProfitGridView->AllowUserToResizeRows = false;
			this->ProfitGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->ProfitGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->ProfitGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ProfitGridView->DefaultCellStyle = dataGridViewCellStyle4;
			this->ProfitGridView->Location = System::Drawing::Point(12, 33);
			this->ProfitGridView->MultiSelect = false;
			this->ProfitGridView->Name = L"ProfitGridView";
			this->ProfitGridView->ReadOnly = true;
			this->ProfitGridView->RowHeadersWidth = 51;
			this->ProfitGridView->RowTemplate->Height = 24;
			this->ProfitGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ProfitGridView->Size = System::Drawing::Size(711, 106);
			this->ProfitGridView->TabIndex = 13;
			// 
			// ProfitLabel
			// 
			this->ProfitLabel->AutoSize = true;
			this->ProfitLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ProfitLabel->Location = System::Drawing::Point(9, 12);
			this->ProfitLabel->Name = L"ProfitLabel";
			this->ProfitLabel->Size = System::Drawing::Size(116, 18);
			this->ProfitLabel->TabIndex = 16;
			this->ProfitLabel->Text = L"Прибыль ГАИ";
			// 
			// MostLawersGridView
			// 
			this->MostLawersGridView->AllowUserToAddRows = false;
			this->MostLawersGridView->AllowUserToDeleteRows = false;
			this->MostLawersGridView->AllowUserToResizeColumns = false;
			this->MostLawersGridView->AllowUserToResizeRows = false;
			this->MostLawersGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->MostLawersGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->MostLawersGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->MostLawersGridView->DefaultCellStyle = dataGridViewCellStyle5;
			this->MostLawersGridView->Location = System::Drawing::Point(12, 163);
			this->MostLawersGridView->MultiSelect = false;
			this->MostLawersGridView->Name = L"MostLawersGridView";
			this->MostLawersGridView->ReadOnly = true;
			this->MostLawersGridView->RowHeadersWidth = 51;
			this->MostLawersGridView->RowTemplate->Height = 24;
			this->MostLawersGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->MostLawersGridView->Size = System::Drawing::Size(711, 193);
			this->MostLawersGridView->TabIndex = 13;
			// 
			// MostFinersGridView
			// 
			this->MostFinersGridView->AllowUserToAddRows = false;
			this->MostFinersGridView->AllowUserToDeleteRows = false;
			this->MostFinersGridView->AllowUserToResizeColumns = false;
			this->MostFinersGridView->AllowUserToResizeRows = false;
			this->MostFinersGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->MostFinersGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->MostFinersGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->MostFinersGridView->DefaultCellStyle = dataGridViewCellStyle6;
			this->MostFinersGridView->Location = System::Drawing::Point(12, 380);
			this->MostFinersGridView->MultiSelect = false;
			this->MostFinersGridView->Name = L"MostFinersGridView";
			this->MostFinersGridView->ReadOnly = true;
			this->MostFinersGridView->RowHeadersWidth = 51;
			this->MostFinersGridView->RowTemplate->Height = 24;
			this->MostFinersGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->MostFinersGridView->Size = System::Drawing::Size(711, 193);
			this->MostFinersGridView->TabIndex = 13;
			// 
			// MostLawersLabel
			// 
			this->MostLawersLabel->AutoSize = true;
			this->MostLawersLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MostLawersLabel->Location = System::Drawing::Point(9, 142);
			this->MostLawersLabel->Name = L"MostLawersLabel";
			this->MostLawersLabel->Size = System::Drawing::Size(307, 18);
			this->MostLawersLabel->TabIndex = 19;
			this->MostLawersLabel->Text = L"5 самых частонарушаемых водителей";
			// 
			// MostFinersLabel
			// 
			this->MostFinersLabel->AutoSize = true;
			this->MostFinersLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MostFinersLabel->Location = System::Drawing::Point(12, 359);
			this->MostFinersLabel->Name = L"MostFinersLabel";
			this->MostFinersLabel->Size = System::Drawing::Size(285, 18);
			this->MostFinersLabel->TabIndex = 20;
			this->MostFinersLabel->Text = L"5 самых частонарушаемых статьей";
			// 
			// Stats
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(735, 626);
			this->Controls->Add(this->MostFinersLabel);
			this->Controls->Add(this->MostLawersLabel);
			this->Controls->Add(this->MostFinersGridView);
			this->Controls->Add(this->MostLawersGridView);
			this->Controls->Add(this->ProfitLabel);
			this->Controls->Add(this->ProfitGridView);
			this->Controls->Add(this->RefreshLabel);
			this->Controls->Add(this->RefreshBtn);
			this->Controls->Add(this->BackBtn);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Stats";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Статистика";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProfitGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MostLawersGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MostFinersGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
		void InitializeAddingComponents(void) {
			ProfitGridView->DataSource = nullptr;
			MostFinersGridView->DataSource = nullptr;
			MostLawersGridView->DataSource = nullptr;

			ProfitGridView->DataSource = database_.ProfitTableStatistics();
			MostFinersGridView->DataSource = database_.MostFinersTableStatistics();
			MostLawersGridView->DataSource = database_.MostLawersTableStatistics();

			ProfitGridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(this->ProfitGridView->Font, System::Drawing::FontStyle::Bold);
			ProfitGridView->Columns[0]->DefaultCellStyle->Font = gcnew System::Drawing::Font(this->ProfitGridView->Font, System::Drawing::FontStyle::Bold);
			ProfitGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			ProfitGridView->ClearSelection();
			ProfitGridView->ReadOnly = true;

			MostFinersGridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(this->ProfitGridView->Font, System::Drawing::FontStyle::Bold);
			MostFinersGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			MostFinersGridView->ClearSelection();
			MostFinersGridView->ReadOnly = true;

			MostLawersGridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(this->ProfitGridView->Font, System::Drawing::FontStyle::Bold);
			MostLawersGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			MostLawersGridView->ClearSelection();
			MostLawersGridView->ReadOnly = true;
		}
#pragma endregion
	private: System::Void BackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void RefreshBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		InitializeAddingComponents();
	}
};
}
