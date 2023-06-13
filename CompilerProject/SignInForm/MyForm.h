#pragma once
#include "MyForm1.h"

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

namespace SignInForm
{

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
public
    ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            pnlTerms->Hide(); // To Hide the Terms & Conditions initially when the program runs.
            // CompilerPanel->Hide(); //To Hide the CC Panel initially when the program runs.
            // LexicalPanel->Hide();
            //  TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label ^ label1;

    private:
        System::Windows::Forms::Label ^ label2;

    private:
        System::Windows::Forms::Label ^ label3;

    private:
        System::Windows::Forms::TextBox ^ textBox1;

    private:
        System::Windows::Forms::Panel ^ panel1;

    private:
        System::Windows::Forms::TextBox ^ textBox2;

    private:
        System::Windows::Forms::Panel ^ panel2;

    private:
        System::Windows::Forms::CheckBox ^ checkBox1;

    private:
        System::Windows::Forms::Label ^ label4;

    private:
        System::Windows::Forms::Button ^ button1;

    private:
        System::Windows::Forms::Button ^ button2;

    private:
        System::Windows::Forms::Label ^ label5;

    private:
        System::Windows::Forms::TextBox ^ textBox3;

    private:
        System::Windows::Forms::Button ^ button3;

    private:
        System::Windows::Forms::Panel ^ pnlTerms;

    protected:
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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->pnlTerms = (gcnew System::Windows::Forms::Panel());
            this->pnlTerms->SuspendLayout();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Black;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28.75F));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(51, 62);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(140, 52);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Sign in";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Black;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
            this->label2->ForeColor = System::Drawing::Color::White;
            this->label2->Location = System::Drawing::Point(57, 156);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(60, 15);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Username";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::Black;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
            this->label3->ForeColor = System::Drawing::Color::White;
            this->label3->Location = System::Drawing::Point(57, 231);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(57, 15);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Password";
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::Color::Black;
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.75F));
            this->textBox1->ForeColor = System::Drawing::Color::White;
            this->textBox1->Location = System::Drawing::Point(60, 174);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(221, 17);
            this->textBox1->TabIndex = 3;
            this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyDown);
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::White;
            this->panel1->Location = System::Drawing::Point(60, 197);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(249, 2);
            this->panel1->TabIndex = 4;
            // 
            // textBox2
            // 
            this->textBox2->BackColor = System::Drawing::Color::Black;
            this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.75F));
            this->textBox2->ForeColor = System::Drawing::Color::White;
            this->textBox2->Location = System::Drawing::Point(60, 249);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(221, 17);
            this->textBox2->TabIndex = 5;
            this->textBox2->UseSystemPasswordChar = true;
            this->textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox2_KeyDown);
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::White;
            this->panel2->Location = System::Drawing::Point(60, 272);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(249, 2);
            this->panel2->TabIndex = 5;
            // 
            // checkBox1
            // 
            this->checkBox1->AutoSize = true;
            this->checkBox1->Checked = true;
            this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
            this->checkBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
            this->checkBox1->ForeColor = System::Drawing::Color::White;
            this->checkBox1->Location = System::Drawing::Point(60, 299);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(95, 19);
            this->checkBox1->TabIndex = 6;
            this->checkBox1->Text = L"I agree to the";
            this->checkBox1->UseVisualStyleBackColor = true;
            this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::Black;
            this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
            this->label4->ForeColor = System::Drawing::Color::DarkRed;
            this->label4->Location = System::Drawing::Point(149, 301);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(122, 15);
            this->label4->TabIndex = 7;
            this->label4->Text = L"Terms and Conditions";
            this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::DarkRed;
            this->button1->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
            this->button1->FlatAppearance->BorderSize = 0;
            this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button1->ForeColor = System::Drawing::Color::White;
            this->button1->Location = System::Drawing::Point(60, 346);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(106, 36);
            this->button1->TabIndex = 8;
            this->button1->Text = L"Sign in";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::Black;
            this->button2->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
            this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button2->ForeColor = System::Drawing::Color::DarkRed;
            this->button2->Location = System::Drawing::Point(172, 346);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(106, 36);
            this->button2->TabIndex = 9;
            this->button2->Text = L"Exit";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F));
            this->label5->ForeColor = System::Drawing::Color::White;
            this->label5->Location = System::Drawing::Point(27, 27);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(213, 30);
            this->label5->TabIndex = 0;
            this->label5->Text = L"Terms and Conditions";
            // 
            // textBox3
            // 
            this->textBox3->BackColor = System::Drawing::Color::Black;
            this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->textBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F));
            this->textBox3->ForeColor = System::Drawing::Color::White;
            this->textBox3->Location = System::Drawing::Point(32, 64);
            this->textBox3->Multiline = true;
            this->textBox3->Name = L"textBox3";
            this->textBox3->ReadOnly = true;
            this->textBox3->Size = System::Drawing::Size(425, 252);
            this->textBox3->TabIndex = 1;
            this->textBox3->Text = resources->GetString(L"textBox3.Text");
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::DarkRed;
            this->button3->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
            this->button3->FlatAppearance->BorderSize = 0;
            this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button3->ForeColor = System::Drawing::Color::White;
            this->button3->Location = System::Drawing::Point(351, 322);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(106, 36);
            this->button3->TabIndex = 9;
            this->button3->Text = L"OK";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            // 
            // pnlTerms
            // 
            this->pnlTerms->BackColor = System::Drawing::Color::Black;
            this->pnlTerms->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlTerms.BackgroundImage")));
            this->pnlTerms->Controls->Add(this->button3);
            this->pnlTerms->Controls->Add(this->textBox3);
            this->pnlTerms->Controls->Add(this->label5);
            this->pnlTerms->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pnlTerms->Location = System::Drawing::Point(0, 0);
            this->pnlTerms->Name = L"pnlTerms";
            this->pnlTerms->Size = System::Drawing::Size(727, 477);
            this->pnlTerms->TabIndex = 10;
            this->pnlTerms->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
            this->pnlTerms->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
            this->pnlTerms->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
            // 
            // MyForm
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(727, 477);
            this->Controls->Add(this->pnlTerms);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->checkBox1);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.75F));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Sign In";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
            this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
            this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
            this->pnlTerms->ResumeLayout(false);
            this->pnlTerms->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
        // Set the auto scale mode to none to avoid resizing of form while changing font size.
        // This is done in properties panel under layout section.

    private:
        System::Void checkBox1_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
        {
            if (checkBox1->Checked)
            {
                button1->Enabled = true; // if the checkbox is checked then enable the Sign in Button
            }
            else
            {
                button1->Enabled = false;
            }
        }

    private:
        System::Void button2_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            Application::Exit();
        }

    private:
        static bool isForm1Open = false; // Static variable to track if MyForm2 is open

        System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            if (textBox1->Text == "admin")
            {
                if (textBox2->Text == "admin")
                {
                    if (!isForm1Open)
                    {
                        MyForm1 ^ form1 = gcnew MyForm1();
                        form1->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::MyForm1_FormClosed); // Handle FormClosed event
                        form1->Show();
                        isForm1Open = true;
                    }
                    else
                    {
                        MessageBox::Show("Form is already running!", "Failure", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                    //// MessageBox::Show("Access Granted!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    ////  Create an instance of MyForm1
                    // MyForm1 ^ form1 = gcnew MyForm1();

                    //// Show MyForm1
                    // form1->Show();
                }
                else
                {
                    MessageBox::Show("Incorrect Password!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            else
            {
                MessageBox::Show("Incorrect Username!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

    private:
        System::Void MyForm1_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e)
        {
            isForm1Open = false;
        }

    private:
        System::Void button3_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            pnlTerms->Hide(); // To hide the Terms and Conditions panel initially
        }

    private:
        System::Void label4_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            pnlTerms->Show();
        }

    private:
        System::Void MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
        {
        }
        // Dragging thr Form
        bool dragging;
        Point offset;

    private:
        System::Void MyForm_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
        {
            // enable dragging and get mouse position.
            dragging = true;
            offset.X = e->X;
            offset.Y = e->Y;
        }

    private:
        System::Void MyForm_MouseMove(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
        {
            // check whether able to move.
            if (dragging)
            {
                Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
                Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
            }
        }

    private:
        System::Void MyForm_MouseUp(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
        {
            // disable dragging
            dragging = false;
        }
        // Press ENTER and move to next box automatically.
        // admin
    private:
        System::Void textBox1_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
        {
            if (e->KeyValue == (int)Keys::Enter)
            {
                textBox2->Focus();
            }
        }
        // password
    private:
        System::Void textBox2_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
        {
            if (e->KeyValue == (int)Keys::Enter)
            {
                button1->PerformClick();
            }
        }

    private:
        System::Void button5_Click_1(System::Object ^ sender, System::EventArgs ^ e)
        {
            /*CompilerPanel->Hide();*/
        }
    };
}