#pragma once
#include "User.h"
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
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for Messages
	/// </summary>
	public ref class Messages : public System::Windows::Forms::Form
	{
	public:
		User* currentUser = new User();
		Messages(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();
		}


		void generatelabel1ages()
		{

			this->scrollable_transaction_panel->Controls->Clear();

			int i = 0;
			for (auto it : currentUser->recMsg)
			{

				Panel^ panel = gcnew Panel();
				panel->Size = System::Drawing::Size(680, 118);
				panel->BackColor = System::Drawing::SystemColors::ControlLight;
				panel->Location = System::Drawing::Point(0, (i * 135));

				// PictureBox to the left of senderIdLabel
				// PictureBox to the left of senderIdLabel
				PictureBox^ senderPic = gcnew PictureBox();
				senderPic->Size = System::Drawing::Size(40, 40);
				senderPic->Location = System::Drawing::Point(10, 10);
				senderPic->SizeMode = PictureBoxSizeMode::StretchImage;
				senderPic->Image = System::Drawing::Image::FromFile("C:\\Users\\DELL\\Desktop\\Projects\\OregaCPP\\SarahaMod\\Images\\icon.png");
				senderPic->BorderStyle = BorderStyle::FixedSingle;


				Label^ senderIdLabel = gcnew Label();
				senderIdLabel->Text = it.getSenderId().ToString();
				senderIdLabel->Location = System::Drawing::Point(60, 10); // Shifted right to make space for PictureBox
				senderIdLabel->AutoSize = true;
				senderIdLabel->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold);

				Label^ favTimelabel = gcnew Label();
				favTimelabel->Text = msclr::interop::marshal_as<System::String^>(it.timeStr);
				favTimelabel->Location = System::Drawing::Point(570, 10);
				favTimelabel->AutoSize = true;
				favTimelabel->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold);

				Label^ FavContent = gcnew Label();
				FavContent->Text = msclr::interop::marshal_as<System::String^>(it.getContent());
				FavContent->Location = System::Drawing::Point(10, 60);
				FavContent->AutoSize = true;
				FavContent->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold);

				panel->Controls->Add(senderPic);      // Add PictureBox first (at the back)
				panel->Controls->Add(senderIdLabel);  // Then the label
				panel->Controls->Add(favTimelabel);
				panel->Controls->Add(FavContent);

				this->Controls->Add(panel);
				this->scrollable_transaction_panel->Controls->Add(panel);
				i++;
			}
		}






	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Messages()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Panel^ scrollable_transaction_panel;
	private: System::Windows::Forms::Button^ deleteButton;
	private: System::Windows::Forms::Button^ favButton;
	private: System::Windows::Forms::Button^ button6;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Messages::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->scrollable_transaction_panel = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->favButton = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
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
			this->button1->TabIndex = 2;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Messages::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button2->Location = System::Drawing::Point(650, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(320, 46);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Incoming Messages";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Messages::button2_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->scrollable_transaction_panel);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(3, 51);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(976, 679);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Messages::panel1_Paint);
			// 
			// scrollable_transaction_panel
			// 
			this->scrollable_transaction_panel->AutoScroll = true;
			this->scrollable_transaction_panel->BackColor = System::Drawing::Color::White;
			this->scrollable_transaction_panel->Location = System::Drawing::Point(13, 24);
			this->scrollable_transaction_panel->Name = L"scrollable_transaction_panel";
			this->scrollable_transaction_panel->Size = System::Drawing::Size(950, 620);
			this->scrollable_transaction_panel->TabIndex = 2;
			this->scrollable_transaction_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Messages::scrollable_transaction_panel_Paint);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Location = System::Drawing::Point(166, 199);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(655, 477);
			this->panel2->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(102, 336);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(473, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"You didn\'t recieve any messages yet";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(156, -34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(374, 320);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(100, 96);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button3->Location = System::Drawing::Point(375, 0);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(270, 46);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Favourite";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Messages::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button4->Location = System::Drawing::Point(73, 0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(295, 46);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Sent Messages";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Messages::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::DodgerBlue;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button5->Location = System::Drawing::Point(300, 745);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(392, 46);
			this->button5->TabIndex = 3;
			this->button5->Text = L"Start Sending Messages";
			this->button5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Messages::button5_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->BackColor = System::Drawing::Color::White;
			this->deleteButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->deleteButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->deleteButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deleteButton.Image")));
			this->deleteButton->Location = System::Drawing::Point(915, 736);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(40, 40);
			this->deleteButton->TabIndex = 11;
			this->deleteButton->UseVisualStyleBackColor = false;
			this->deleteButton->Click += gcnew System::EventHandler(this, &Messages::deleteButton_Click);
			// 
			// favButton
			// 
			this->favButton->BackColor = System::Drawing::Color::White;
			this->favButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->favButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->favButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->favButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"favButton.Image")));
			this->favButton->Location = System::Drawing::Point(869, 736);
			this->favButton->Name = L"favButton";
			this->favButton->Size = System::Drawing::Size(40, 40);
			this->favButton->TabIndex = 11;
			this->favButton->UseVisualStyleBackColor = false;
			this->favButton->Click += gcnew System::EventHandler(this, &Messages::favButton_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(16, 752);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(121, 39);
			this->button6->TabIndex = 12;
			this->button6->Text = L"Chat";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Messages::button6_Click);
			// 
			// Messages
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 803);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->favButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Messages";
			this->Text = L"Messages";
			this->Load += gcnew System::EventHandler(this, &Messages::Messages_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: bool switchToWelcome = false;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToWelcome = true;
		this->Close();
	}

	public: bool switchToMessage = false;
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToMessage = true;
		this->Close();
	}

	public: bool switchToFav = false;
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToFav = true;
		this->Close();
	}

	public: bool switchToSent = false;
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToSent = true;
		this->Close();
	}

	public: bool switchToSending = false;
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToSending = true;
		this->Close();
	}

	public: System::String^ msg;
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Text = msg;
	}

	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void Messages_Load(System::Object^ sender, System::EventArgs^ e) {
		if (!currentUser->recMsg.empty()) {
			generatelabel1ages();
		}
		else
		{
			scrollable_transaction_panel->Hide();
		}

	}

	private: System::Void scrollable_transaction_panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Delete
	}

	private: System::Void favButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Favourite
	}

	public: bool switchToChat = false;
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToChat = true;
		this->Close();
	}
};
}