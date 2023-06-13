#pragma once
#include "MyForm2.h"

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

bool Program_Abdullah();

namespace SignInForm
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
public
	ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			LexicalPanel->Hide();
			//
			// TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private:
		System::Windows::Forms::Button ^ button4;

	private:
		System::Windows::Forms::Panel ^ panel3;

	private:
		System::Windows::Forms::Label ^ label8;

	private:
		System::Windows::Forms::Label ^ label7;

	private:
		System::Windows::Forms::Button ^ TreeButton;

	private:
		System::Windows::Forms::Button ^ lexicalButton;

	private:
		System::Windows::Forms::Label ^ label6;

	private:
		System::Windows::Forms::Panel ^ LexicalPanel;

	private:
		System::Windows::Forms::Button ^ button8;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->TreeButton = (gcnew System::Windows::Forms::Button());
			this->lexicalButton = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->LexicalPanel = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->LexicalPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Black;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->ForeColor = System::Drawing::Color::DarkRed;
			this->button4->Location = System::Drawing::Point(306, 399);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(147, 36);
			this->button4->TabIndex = 23;
			this->button4->Text = L"Exit Application";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(182, 90);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(387, 5);
			this->panel3->TabIndex = 22;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Black;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(264, 346);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(430, 15);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Press this button if you want to Generate a Tree for an expression and Evaluate i"
				L"t.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Black;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(41, 217);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(471, 15);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Press this button if you want to Generate Tokens and check the Syntax of the expr"
				L"ession.";
			// 
			// TreeButton
			// 
			this->TreeButton->BackColor = System::Drawing::Color::DarkRed;
			this->TreeButton->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			this->TreeButton->FlatAppearance->BorderSize = 0;
			this->TreeButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->TreeButton->ForeColor = System::Drawing::Color::White;
			this->TreeButton->Location = System::Drawing::Point(511, 271);
			this->TreeButton->Name = L"TreeButton";
			this->TreeButton->Size = System::Drawing::Size(183, 69);
			this->TreeButton->TabIndex = 19;
			this->TreeButton->Text = L"Semantic Analysis";
			this->TreeButton->UseVisualStyleBackColor = false;
			this->TreeButton->Click += gcnew System::EventHandler(this, &MyForm1::TreeButton_Click);
			// 
			// lexicalButton
			// 
			this->lexicalButton->BackColor = System::Drawing::Color::DarkRed;
			this->lexicalButton->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			this->lexicalButton->FlatAppearance->BorderSize = 0;
			this->lexicalButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->lexicalButton->ForeColor = System::Drawing::Color::White;
			this->lexicalButton->Location = System::Drawing::Point(44, 143);
			this->lexicalButton->Name = L"lexicalButton";
			this->lexicalButton->Size = System::Drawing::Size(183, 69);
			this->lexicalButton->TabIndex = 18;
			this->lexicalButton->Text = L"Lexical Analysis";
			this->lexicalButton->UseVisualStyleBackColor = false;
			this->lexicalButton->Click += gcnew System::EventHandler(this, &MyForm1::lexicalButton_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Black;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28.75F));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(173, 38);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(410, 52);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Compiler Construction";
			// 
			// LexicalPanel
			// 
			this->LexicalPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LexicalPanel.BackgroundImage")));
			this->LexicalPanel->Controls->Add(this->button8);
			this->LexicalPanel->Controls->Add(this->textBox5);
			this->LexicalPanel->Controls->Add(this->label11);
			this->LexicalPanel->Controls->Add(this->button7);
			this->LexicalPanel->Controls->Add(this->button6);
			this->LexicalPanel->Controls->Add(this->textBox4);
			this->LexicalPanel->Controls->Add(this->label10);
			this->LexicalPanel->Controls->Add(this->label9);
			this->LexicalPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LexicalPanel->Location = System::Drawing::Point(0, 0);
			this->LexicalPanel->Name = L"LexicalPanel";
			this->LexicalPanel->Size = System::Drawing::Size(735, 473);
			this->LexicalPanel->TabIndex = 25;
			this->LexicalPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm1::LexicalPanel_MouseDown);
			this->LexicalPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm1::LexicalPanel_MouseMove);
			this->LexicalPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm1::LexicalPanel_MouseUp);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Black;
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->ForeColor = System::Drawing::Color::DarkRed;
			this->button8->Location = System::Drawing::Point(285, 408);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(217, 36);
			this->button8->TabIndex = 37;
			this->button8->Text = L"Exit Application";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm1::button8_Click);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::Black;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox5->ForeColor = System::Drawing::Color::White;
			this->textBox5->Location = System::Drawing::Point(335, 146);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(363, 175);
			this->textBox5->TabIndex = 36;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Black;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(332, 128);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(122, 15);
			this->label11->TabIndex = 35;
			this->label11->Text = L"Generated Tokens are:";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Black;
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->ForeColor = System::Drawing::Color::DarkRed;
			this->button7->Location = System::Drawing::Point(396, 366);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(106, 36);
			this->button7->TabIndex = 34;
			this->button7->Text = L"Back";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm1::button7_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::DarkRed;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Location = System::Drawing::Point(284, 366);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(106, 36);
			this->button6->TabIndex = 33;
			this->button6->Text = L"Generate";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm1::button6_Click);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::Black;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox4->ForeColor = System::Drawing::Color::White;
			this->textBox4->Location = System::Drawing::Point(40, 149);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(190, 175);
			this->textBox4->TabIndex = 32;
			this->textBox4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm1::textBox4_KeyDown);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Black;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(38, 128);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(96, 15);
			this->label10->TabIndex = 31;
			this->label10->Text = L"Enter Expression:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Black;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28.75F));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(237, 29);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(293, 52);
			this->label9->TabIndex = 30;
			this->label9->Text = L"Lexical Analyzer";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(735, 473);
			this->Controls->Add(this->LexicalPanel);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->TreeButton);
			this->Controls->Add(this->lexicalButton);
			this->Controls->Add(this->label6);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm1";
			this->Text = L"Compiler";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm1::MyForm1_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm1::MyForm1_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm1::MyForm1_MouseUp);
			this->LexicalPanel->ResumeLayout(false);
			this->LexicalPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void lexicalButton_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			LexicalPanel->Show();
		}

	private:
		System::Void button5_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			// MyForm^ form1 = gcnew MyForm();

			//// Show MyForm1
			// form1->Show();
		}

	private:
		System::Void button4_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			Application::Exit();
		}

	private:
		System::Void button8_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			Application::Exit();
		}

	private:
		System::Void button7_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			LexicalPanel->Hide();
			textBox4->Text = "";
			textBox5->Text = "";
		}
		// Dragging thr Form
		bool dragging;
		Point offset;

	private:
		System::Void MyForm1_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			// enable dragging and get mouse position.
			dragging = true;
			offset.X = e->X;
			offset.Y = e->Y;
		}

	private:
		System::Void MyForm1_MouseMove(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			// check whether able to move.
			if (dragging)
			{
				Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
				Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
			}
		}

	private:
		System::Void MyForm1_MouseUp(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			// disable dragging
			dragging = false;
		}

	private:
		System::Void button6_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			String ^ text = textBox4->Text; // Get the text from textBox4
											// Write the text to the file "Expression.txt"
			System::IO::File::WriteAllText("Expression.txt", text);

			if (Program_Abdullah())
			{
				MessageBox::Show("Token Generation was Successfull!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				// Read the text from the file "TokensGen.txt"
				try
				{
					String^ text2 = System::IO::File::ReadAllText("TokenGen.txt");
					textBox5->Text = text2; // Display the text in textBox2
				}
				catch (System::IO::IOException^ ex)
				{
					MessageBox::Show("Error reading file: " + ex->Message);
				}
			}
			else
			{
				MessageBox::Show("Token Generation was Unsuccessfull!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); // Show a message box with the text "Unsuccessful"
			}
			// Read the text from the file "TokensGen.txt"
		//	try
		//	{
		//		String ^ text2 = System::IO::File::ReadAllText("TokenGen.txt");
		//		textBox5->Text = text2; // Display the text in textBox2
		//	}
		//	catch (System::IO::IOException ^ ex)
		//	{
		//		MessageBox::Show("Error reading file: " + ex->Message);
		//	}
		}

	private:
		System::Void textBox4_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
		{
			if (e->KeyValue == (int)Keys::Enter)
			{
				button6->PerformClick();
			}
		}

		static bool isForm2Open = false; // Static variable to track if MyForm2 is open

	private:
		System::Void TreeButton_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			if (!isForm2Open)
			{
				MyForm2 ^ form2 = gcnew MyForm2();
				form2->FormClosed += gcnew FormClosedEventHandler(this, &MyForm1::MyForm2_FormClosed); // Handle FormClosed event
				form2->Show();
				isForm2Open = true;
			}
			else
			{
				MessageBox::Show("Form is already running!", "Failure", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			// Create an instance of MyForm1
			// MyForm2 ^ form1 = gcnew MyForm2();

			//// Show MyForm1
			// form1->Show();
		}

	private:
		System::Void MyForm2_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e)
		{
			isForm2Open = false;
		}

	private:
		System::Void LexicalPanel_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			// enable dragging and get mouse position.
			dragging = true;
			offset.X = e->X;
			offset.Y = e->Y;
		}

	private:
		System::Void LexicalPanel_MouseMove(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			// check whether able to move.
			if (dragging)
			{
				Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
				Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
			}
		}

	private:
		System::Void LexicalPanel_MouseUp(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			// disable dragging
			dragging = false;
		}
	};
}
