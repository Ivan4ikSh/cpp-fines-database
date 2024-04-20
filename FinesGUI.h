#pragma once
#include "Violations.h"
#include "Payments.h"
#include "Stats.h"

namespace FinesDatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FinesGUI
	/// </summary>
	public ref class FinesGUI : public System::Windows::Forms::Form
	{
	public:
		FinesGUI(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FinesGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ StatisticBtn;
	protected:
	private: System::Windows::Forms::Button^ PaymentsBtn;
	private: System::Windows::Forms::Button^ ViolationBtn;

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
			this->StatisticBtn = (gcnew System::Windows::Forms::Button());
			this->PaymentsBtn = (gcnew System::Windows::Forms::Button());
			this->ViolationBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// StatisticBtn
			// 
			this->StatisticBtn->Location = System::Drawing::Point(124, 235);
			this->StatisticBtn->Name = L"StatisticBtn";
			this->StatisticBtn->Size = System::Drawing::Size(192, 47);
			this->StatisticBtn->TabIndex = 5;
			this->StatisticBtn->Text = L"Посмотреть статистику";
			this->StatisticBtn->UseVisualStyleBackColor = true;
			this->StatisticBtn->Click += gcnew System::EventHandler(this, &FinesGUI::StatisticBtn_Click);
			// 
			// PaymentsBtn
			// 
			this->PaymentsBtn->Location = System::Drawing::Point(124, 182);
			this->PaymentsBtn->Name = L"PaymentsBtn";
			this->PaymentsBtn->Size = System::Drawing::Size(192, 47);
			this->PaymentsBtn->TabIndex = 4;
			this->PaymentsBtn->Text = L"Получить данные о платежах";
			this->PaymentsBtn->UseVisualStyleBackColor = true;
			this->PaymentsBtn->Click += gcnew System::EventHandler(this, &FinesGUI::PaymentsBtn_Click);
			// 
			// ViolationBtn
			// 
			this->ViolationBtn->Location = System::Drawing::Point(124, 129);
			this->ViolationBtn->Name = L"ViolationBtn";
			this->ViolationBtn->Size = System::Drawing::Size(192, 47);
			this->ViolationBtn->TabIndex = 3;
			this->ViolationBtn->Text = L"Зарегистрировать нарушение";
			this->ViolationBtn->UseVisualStyleBackColor = true;
			this->ViolationBtn->Click += gcnew System::EventHandler(this, &FinesGUI::ViolationBtn_Click);
			// 
			// FinesGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(448, 416);
			this->Controls->Add(this->StatisticBtn);
			this->Controls->Add(this->PaymentsBtn);
			this->Controls->Add(this->ViolationBtn);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"FinesGUI";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"База данных штрафов ГИБДД";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		this->Show(); // Показать первую форму после закрытия второй
	}

	private: System::Void ViolationBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Violations^ v = gcnew Violations();
		v->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FinesGUI::FormClosed);
		v->Show();
		this->Hide();
	}

	private: System::Void PaymentsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Payments^ p = gcnew Payments();
		p->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FinesGUI::FormClosed);
		p->Show();
		this->Hide();
	}
	private: System::Void StatisticBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Stats^ s = gcnew Stats();
		s->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FinesGUI::FormClosed);
		s->Show();
		this->Hide();
	}
};
}
