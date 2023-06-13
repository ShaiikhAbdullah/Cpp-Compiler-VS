#pragma once
// #include "MyForm1.h"

#include <Windows.h>
#include <msclr/marshal.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

void runProgram();

namespace SignInForm
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
public
	ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			// TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Button ^ button8;

	protected:
	private:
		System::Windows::Forms::TextBox ^ textBox5;

	private:
		System::Windows::Forms::Label ^ label11;

	private:
		System::Windows::Forms::Button ^ button7;

	private:
		System::Windows::Forms::Button ^ button6;

	private:
		System::Windows::Forms::TextBox ^ textBox4;

	private:
		System::Windows::Forms::Label ^ label10;

	private:
		System::Windows::Forms::Label ^ label9;

	private:
		System::Windows::Forms::Label ^ label1;

	private:
		System::Windows::Forms::Label ^ label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager ^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			//
			// button8
			//
			this->button8->BackColor = System::Drawing::Color::Black;
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->ForeColor = System::Drawing::Color::DarkRed;
			this->button8->Location = System::Drawing::Point(262, 423);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(217, 36);
			this->button8->TabIndex = 45;
			this->button8->Text = L"Exit Application";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm2::button8_Click);
			//
			// textBox5
			//
			this->textBox5->BackColor = System::Drawing::Color::Black;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox5->ForeColor = System::Drawing::Color::White;
			this->textBox5->Location = System::Drawing::Point(332, 132);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(363, 175);
			this->textBox5->TabIndex = 44;
			//
			// label11
			//
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Black;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(329, 114);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(99, 15);
			this->label11->TabIndex = 43;
			this->label11->Text = L"Generated Tree is:";
			//
			// button7
			//
			this->button7->BackColor = System::Drawing::Color::Black;
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->ForeColor = System::Drawing::Color::DarkRed;
			this->button7->Location = System::Drawing::Point(373, 381);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(106, 36);
			this->button7->TabIndex = 42;
			this->button7->Text = L"Back";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm2::button7_Click);
			//
			// button6
			//
			this->button6->BackColor = System::Drawing::Color::DarkRed;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Location = System::Drawing::Point(261, 381);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(106, 36);
			this->button6->TabIndex = 41;
			this->button6->Text = L"Generate";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm2::button6_Click);
			//
			// textBox4
			//
			this->textBox4->BackColor = System::Drawing::Color::Black;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox4->ForeColor = System::Drawing::Color::White;
			this->textBox4->Location = System::Drawing::Point(37, 135);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(190, 175);
			this->textBox4->TabIndex = 40;
			this->textBox4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm2::textBox4_KeyDown);
			//
			// label10
			//
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Black;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(35, 114);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(96, 15);
			this->label10->TabIndex = 39;
			this->label10->Text = L"Enter Expression:";
			//
			// label9
			//
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Black;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28.75F));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(216, 15);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(338, 52);
			this->label9->TabIndex = 38;
			this->label9->Text = L"Semantic Analyzer";
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(332, 317);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 15);
			this->label1->TabIndex = 46;
			this->label1->Text = L"The evaluated expression RESULT is:";
			//
			// label2
			//
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
															  static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(522, 313);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 20);
			this->label2->TabIndex = 47;
			this->label2->Text = L"Answer";
			//
			// MyForm2
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(727, 481);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm2";
			this->Text = L"Semantic Analyzer";
			// this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm2::MyForm2_FormClosed);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm2::MyForm2_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm2::MyForm2_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm2::MyForm2_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void button6_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			String ^ text = textBox4->Text; // Get the text from textBox1

			// Write the text to the file "Expression.txt"
			System::IO::File::WriteAllText("TreeExp.txt", text);

			runProgram();

			// Read the text from the file "TreeGen.txt"
			try
			{
				String ^ text2 = System::IO::File::ReadAllText("TreeGeneration.txt");
				textBox5->Text = text2; // Display the text in textBox5

				// Clear the file "TreeGen.txt"
				// System::IO::File::Delete("TreeGen.txt");
			}
			catch (System::IO::IOException ^ ex)
			{
				MessageBox::Show("Error reading file: " + ex->Message);
			}

			String ^ text3 = System::IO::File::ReadAllText("EvaluateExpression.txt");
			label2->Text = text3; // Display the text in textBox2
		}

	private:
		System::Void button7_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			// MyForm1^ form1 = gcnew MyForm1();

			//// Show MyForm1
			// form1->Show();
			Application::Exit();
		}

	private:
		System::Void button8_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			Application::Exit();
		}

	private:
		System::Void textBox4_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
		{
			if (e->KeyValue == (int)Keys::Enter)
			{
				button6->PerformClick();
			}
		}

		// Dragging thr Form
		bool dragging;
		Point offset;

	private:
		System::Void MyForm2_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			// enable dragging and get mouse position.
			dragging = true;
			offset.X = e->X;
			offset.Y = e->Y;
		}

	private:
		System::Void MyForm2_MouseMove(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			// check whether able to move.
			if (dragging)
			{
				Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
				Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
			}
		}

	private:
		System::Void MyForm2_MouseUp(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			// disable dragging
			dragging = false;
		}
	};
}
