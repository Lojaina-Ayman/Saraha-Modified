#pragma once
#include "User.h"
#include "Sending.h"
#include "Login.h"
#include "Message.h"
#include <msclr/marshal_cppstd.h>
#include <vector>

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Profile
	/// </summary>
	public ref class Profile : public System::Windows::Forms::Form
	{
	public:
		Profile(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();

			this->usernameLabel->Text = msclr::interop::marshal_as<System::String^>(Login::currentUser->username);
			this->IDLabel->Text = Login::currentUser->id.ToString();
			this->sentCountLabel->Text = Login::currentUser->sentMsg.size().ToString();
			this->recCountLabel->Text = Login::currentUser->recMsg.size().ToString();
		}

		void generatelabel1ages()
		{
			this->scrollable_transaction_panel->Controls->Clear();

			int i = 0;
			for (auto it :Login:: currentUser->viewContactsSortedByMsgCount())
			{
				Panel^ panel = gcnew Panel();
				panel->Size = System::Drawing::Size(680, 118);
				panel->BackColor = System::Drawing::SystemColors::ControlLight;
				panel->Location = System::Drawing::Point(0, (i * 135));

				PictureBox^ senderPic = gcnew PictureBox();
				senderPic->Size = System::Drawing::Size(80, 80);
				senderPic->Location = System::Drawing::Point(10, 20);
				senderPic->Image = System::Drawing::Image::FromFile("Images\\icon.png");
				senderPic->SizeMode = PictureBoxSizeMode::StretchImage;
				senderPic->BorderStyle = BorderStyle::FixedSingle;
			
				Label^ ContactNameLabel = gcnew Label();
				ContactNameLabel->Text = msclr::interop::marshal_as<System::String^>(it.contactName);
				ContactNameLabel->Location = System::Drawing::Point(100, 40);
				ContactNameLabel->AutoSize = true;
				ContactNameLabel->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold);
				ContactNameLabel->Tag = panel;
				panel->Controls->Add(ContactNameLabel);
				panel->Controls->Add(senderPic);
				this->scrollable_transaction_panel->Controls->Add(panel);
				i++;
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Profile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Panel^ scrollable_transaction_panel;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ IDLabel;
	private: System::Windows::Forms::Label^ recCountLabel;
	private: System::Windows::Forms::Label^ sentCountLabel;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Profile::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->recCountLabel = (gcnew System::Windows::Forms::Label());
			this->sentCountLabel = (gcnew System::Windows::Forms::Label());
			this->IDLabel = (gcnew System::Windows::Forms::Label());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->scrollable_transaction_panel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->scrollable_transaction_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DodgerBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(3, 51);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(42, 42);
			this->button2->TabIndex = 6;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Profile::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DodgerBlue;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(42, 42);
			this->button1->TabIndex = 7;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Profile::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(715, 17);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(159, 134);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(206, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(161, 32);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Username:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(206, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 32);
			this->label2->TabIndex = 9;
			this->label2->Text = L"ID:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(206, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(231, 32);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Messages Sent:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(206, 133);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(295, 32);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Messages Received:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->recCountLabel);
			this->panel1->Controls->Add(this->sentCountLabel);
			this->panel1->Controls->Add(this->IDLabel);
			this->panel1->Controls->Add(this->usernameLabel);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(96, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(883, 176);
			this->panel1->TabIndex = 10;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, -3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(203, 188);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// recCountLabel
			// 
			this->recCountLabel->AutoSize = true;
			this->recCountLabel->BackColor = System::Drawing::SystemColors::HotTrack;
			this->recCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recCountLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->recCountLabel->Location = System::Drawing::Point(505, 133);
			this->recCountLabel->Name = L"recCountLabel";
			this->recCountLabel->Size = System::Drawing::Size(114, 32);
			this->recCountLabel->TabIndex = 9;
			this->recCountLabel->Text = L"Number";
			// 
			// sentCountLabel
			// 
			this->sentCountLabel->AutoSize = true;
			this->sentCountLabel->BackColor = System::Drawing::SystemColors::HotTrack;
			this->sentCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sentCountLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->sentCountLabel->Location = System::Drawing::Point(441, 94);
			this->sentCountLabel->Name = L"sentCountLabel";
			this->sentCountLabel->Size = System::Drawing::Size(114, 32);
			this->sentCountLabel->TabIndex = 9;
			this->sentCountLabel->Text = L"Number";
			// 
			// IDLabel
			// 
			this->IDLabel->AutoSize = true;
			this->IDLabel->BackColor = System::Drawing::SystemColors::HotTrack;
			this->IDLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IDLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->IDLabel->Location = System::Drawing::Point(255, 54);
			this->IDLabel->Name = L"IDLabel";
			this->IDLabel->Size = System::Drawing::Size(41, 32);
			this->IDLabel->TabIndex = 9;
			this->IDLabel->Text = L"ID";
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->BackColor = System::Drawing::SystemColors::HotTrack;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->usernameLabel->Location = System::Drawing::Point(360, 15);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(144, 32);
			this->usernameLabel->TabIndex = 9;
			this->usernameLabel->Text = L"Username";
			// 
			// scrollable_transaction_panel
			// 
			this->scrollable_transaction_panel->AutoScroll = true;
			this->scrollable_transaction_panel->BackColor = System::Drawing::Color::White;
			this->scrollable_transaction_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"scrollable_transaction_panel.BackgroundImage")));
			this->scrollable_transaction_panel->Controls->Add(this->pictureBox3);
			this->scrollable_transaction_panel->Controls->Add(this->label5);
			this->scrollable_transaction_panel->Location = System::Drawing::Point(17, 185);
			this->scrollable_transaction_panel->Name = L"scrollable_transaction_panel";
			this->scrollable_transaction_panel->Size = System::Drawing::Size(950, 606);
			this->scrollable_transaction_panel->TabIndex = 11;
			this->scrollable_transaction_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Profile::scrollable_transaction_panel_Paint);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(348, 0);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(62, 55);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox3->TabIndex = 0;
			this->pictureBox3->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(416, 5);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(187, 46);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Contacts";
			// 
			// Profile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 803);
			this->Controls->Add(this->scrollable_transaction_panel);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Profile";
			this->Text = L"Profile";
			this->Load += gcnew System::EventHandler(this, &Profile::Profile_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->scrollable_transaction_panel->ResumeLayout(false);
			this->scrollable_transaction_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: bool switchToSending = false;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToSending = true;
		this->Close();
	}

	public: bool switchToWelcome = false;
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToWelcome = true;
		this->Close();
	}
private: System::Void scrollable_transaction_panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void Profile_Load(System::Object^ sender, System::EventArgs^ e) {
	generatelabel1ages();
}
};
}
