#pragma once
#include "User.h"
#include "Message.h"
#include <msclr/marshal_cppstd.h>
#include <vector>
#include "Login.h"

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for Favourite
	/// </summary>
	public ref class Favourite : public System::Windows::Forms::Form
	{
	public:
		Favourite(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();
		}



		void generateFavMessages()
		{
			
			this->scrollable_panel->Controls->Clear();

			int y = 0;
			for (auto it : Login::currentUser->queueTolist(Login::currentUser->favMsg))
			{
					
				Panel^ panel = gcnew Panel();
				panel->Size = System::Drawing::Size(680, 118);
				panel->BackColor = System::Drawing::SystemColors::ControlLight;
				panel->Location = System::Drawing::Point(0, y);

				
				PictureBox^ senderPic = gcnew PictureBox();
				senderPic->Size = System::Drawing::Size(40, 40);
				senderPic->Location = System::Drawing::Point(10, 10);
				senderPic->SizeMode = PictureBoxSizeMode::StretchImage;
				senderPic->Image = System::Drawing::Image::FromFile("Images\\icon.png");
				senderPic->BorderStyle = BorderStyle::FixedSingle;


				Label^ senderIdLabel = gcnew Label();
				// Trying to find if the sender is a contact or not conditions
				auto& contacts = Login::currentUser->contacts;
				int senderId = it.getSenderId();
				auto itContact = contacts.find(senderId);
				if (itContact != contacts.end()) {
					//  If we Found the contact use contact name
					senderIdLabel->Text = msclr::interop::marshal_as<System::String^>(itContact->second.getName());
				}
				else {
					
					senderIdLabel->Text = senderId.ToString();
				}

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
				FavContent->MaximumSize = System::Drawing::Size(660, 0);
				FavContent->AutoSize = true;
				FavContent->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular);
				FavContent->AutoEllipsis = false;

				panel->Controls->Add(senderPic);      
				panel->Controls->Add(senderIdLabel);  
				panel->Controls->Add(favTimelabel);
				panel->Controls->Add(FavContent);

				this->Controls->Add(panel);
				panel->Height = FavContent->Bottom + 50;
				this->scrollable_panel->Controls->Add(panel);
				y += panel->Height + 10;
			}
		}

		




	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Favourite()
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
	private: System::Windows::Forms::Label^ FavMess;

	private: System::Windows::Forms::PictureBox^ FavStar;

	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ deleteButton;
  private: System::Windows::Forms::Panel^ scrollable_panel;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Favourite::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->FavMess = (gcnew System::Windows::Forms::Label());
			this->FavStar = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->scrollable_panel = (gcnew System::Windows::Forms::Panel());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FavStar))->BeginInit();
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
			this->button1->Click += gcnew System::EventHandler(this, &Favourite::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->button2->Click += gcnew System::EventHandler(this, &Favourite::button2_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(3, 51);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(976, 679);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Favourite::panel1_Paint);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->FavMess);
			this->panel2->Controls->Add(this->FavStar);
			this->panel2->Location = System::Drawing::Point(166, 199);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(655, 477);
			this->panel2->TabIndex = 0;
			// 
			// FavMess
			// 
			this->FavMess->AutoSize = true;
			this->FavMess->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FavMess->Location = System::Drawing::Point(102, 336);
			this->FavMess->Name = L"FavMess";
			this->FavMess->Size = System::Drawing::Size(473, 32);
			this->FavMess->TabIndex = 1;
			this->FavMess->Text = L"You didn\'t recieve any messages yet";
			// 
			// FavStar
			// 
			this->FavStar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FavStar.Image")));
			this->FavStar->Location = System::Drawing::Point(156, -34);
			this->FavStar->Name = L"FavStar";
			this->FavStar->Size = System::Drawing::Size(374, 320);
			this->FavStar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->FavStar->TabIndex = 0;
			this->FavStar->TabStop = false;
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
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button3->Location = System::Drawing::Point(375, 0);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(270, 46);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Favourites";
			this->button3->UseVisualStyleBackColor = false;
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
			this->button4->Click += gcnew System::EventHandler(this, &Favourite::button4_Click);
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
			this->button5->Click += gcnew System::EventHandler(this, &Favourite::button5_Click);
			// 
			// scrollable_panel
			// 
			this->scrollable_panel->AutoScroll = true;
			this->scrollable_panel->BackColor = System::Drawing::Color::White;
			this->scrollable_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"scrollable_panel.BackgroundImage")));
			this->scrollable_panel->Location = System::Drawing::Point(10, 50);
			this->scrollable_panel->Name = L"scrollable_panel";
			this->scrollable_panel->Size = System::Drawing::Size(950, 620);
			this->scrollable_panel->TabIndex = 2;
			this->scrollable_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Favourite::scrollable_panel_Paint);
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
			this->deleteButton->TabIndex = 10;
			this->deleteButton->UseVisualStyleBackColor = false;
			this->deleteButton->Click += gcnew System::EventHandler(this, &Favourite::deleteButton_Click);
			// 
			// Favourite
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 803);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->scrollable_panel);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Favourite";
			this->Text = L"Favourite";
			this->Load += gcnew System::EventHandler(this, &Favourite::Favourite_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FavStar))->EndInit();
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
private: System::Void Favourite_Load(System::Object^ sender, System::EventArgs^ e) {
	if(!Login::currentUser->favMsg.empty()){
		FavStar->Hide();
		FavMess->Hide();
		generateFavMessages();
	}
	else
	{
		FavStar->Show();
		FavMess->Show();
		scrollable_panel->Hide();
	}

}

private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if(Login::currentUser->favMsg.size() == 1){ //To remove the last message
		// Remove the oldest favorite message
		Login::currentUser->removeOldestFavoriteMessage();
		Login::currentUser->saveAllUsers("users.dat");
		// Refresh
		FavStar->Show();
		FavMess->Show();
		scrollable_panel->Hide();
		deleteButton->Hide();
		generateFavMessages();
		
	}
	if (!Login::currentUser->favMsg.empty()) {
		// Remove the oldest favorite message
		Login::currentUser->removeOldestFavoriteMessage();
		Login::currentUser->saveAllUsers("users.dat");
		// Refresh
		generateFavMessages();
	}
		
}
private: System::Void scrollable_panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
