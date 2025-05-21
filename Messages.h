#pragma once
#include "User.h"
#include"Login.h"
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
		
		bool saveContact = false;
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
			this->scrollable_panel->Controls->Clear();

			int i = 0;
			for (auto it : Login::currentUser->recMsg)
			{
				Panel^ panel = gcnew Panel();
				panel->Size = System::Drawing::Size(680, 118);
				panel->BackColor = System::Drawing::SystemColors::ControlLight;
				panel->Location = System::Drawing::Point(0, (i * 135));

				PictureBox^ senderPic = gcnew PictureBox();
				senderPic->Size = System::Drawing::Size(40, 40);
				senderPic->Location = System::Drawing::Point(10, 10);
				senderPic->SizeMode = PictureBoxSizeMode::StretchImage;
				senderPic->BorderStyle = BorderStyle::FixedSingle;

				Label^ senderIdLabel = gcnew Label();
				int senderId = it.getSenderId();
				bool isContact = Login::currentUser->searchContact(senderId);

				if (isContact) {
					std::string contactName;
					auto itContact = Login::currentUser->contacts.find(senderId);
					if (itContact != Login::currentUser->contacts.end()) {
						contactName = itContact->second.getName();
					}
					else {
						contactName = std::to_string(senderId);
					}
					senderIdLabel->Text = gcnew System::String(contactName.c_str());
				}
				else {
					senderIdLabel->Text = senderId.ToString();
					senderIdLabel->Click += gcnew System::EventHandler(this, &Messages::senderIdLabel_Click);
				}
				senderIdLabel->Location = System::Drawing::Point(60, 10);
				senderIdLabel->AutoSize = true;
				senderIdLabel->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold);
				senderIdLabel->Tag = panel;

				Label^ Timelabel = gcnew Label();
				Timelabel->Text = msclr::interop::marshal_as<System::String^>(it.timeStr);
				Timelabel->Location = System::Drawing::Point(570, 10);
				Timelabel->AutoSize = true;
				Timelabel->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold);

				Label^ FavContent = gcnew Label();
				FavContent->Text = msclr::interop::marshal_as<System::String^>(it.getContent());
				FavContent->Location = System::Drawing::Point(10, 60);
				FavContent->AutoSize = true;
				FavContent->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold);

				
				// --- Add Delete Button ---
				Button^ buttonA = gcnew Button();
				buttonA->Name = it.messageid.ToString();
				buttonA->Text = "";
				buttonA->Size = System::Drawing::Size(80, 30);
				buttonA->Location = System::Drawing::Point(120, 80);
				buttonA->Tag = panel; // or any relevant data
				buttonA->Click += gcnew System::EventHandler(this, &Messages::deleteButton_Click);

				// Set image for the Delete button
				buttonA->Image = System::Drawing::Image::FromFile("C:\\Users\\20102\\source\\repos\\Saraha-Modifiedss\\Images\\delete icon.png");
				buttonA->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft; // Adjust as needed
				panel->Controls->Add(buttonA);

				// --- Add Button B ---
				// --- Add Button B ---
				Button^ buttonB = gcnew Button();
				buttonB->Name = senderIdLabel->Text + "|" + FavContent->Text + "|" + Timelabel->Text;
				buttonB->Text = "";
				buttonB->Size = System::Drawing::Size(80, 30);
				buttonB->Location = System::Drawing::Point(210, 80);
				buttonB->Tag = it.messageid; // Store the message ID
				buttonB->Click += gcnew System::EventHandler(this, &Messages::favButton_Click);

				// Set image for the Favorite button
				//buttonB->Image = System::Drawing::Image::FromFile("C:\\Users\\20102\\source\\repos\\Saraha-Modi\\Images\\icons_star_30px.png");
				buttonB->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft; // or another alignment as you prefer

				panel->Controls->Add(buttonB);


				panel->Controls->Add(senderPic);
				panel->Controls->Add(Timelabel);
				panel->Controls->Add(FavContent);
				panel->Controls->Add(senderIdLabel);


				// Add 3-dot button only if sender is a contact
				if (isContact) {
					Button^ RemoveContactButton = gcnew Button();
					RemoveContactButton->Text = "";
					RemoveContactButton->Size = System::Drawing::Size(40, 40);
					RemoveContactButton->Location = System::Drawing::Point(panel->Width - RemoveContactButton->Width - 10, panel->Height - RemoveContactButton->Height - 10);
					RemoveContactButton->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Right);
					//RemoveContactButton->Image = System::Drawing::Image::FromFile("C:\\Users\\20102\\source\\repos\\Saraha-Modi\\Images\\3 dots icon.jpg");
					RemoveContactButton->ImageAlign = System::Drawing::ContentAlignment::MiddleCenter;
					RemoveContactButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					RemoveContactButton->Tag = gcnew Tuple<int, Panel^>(senderId, panel);
					RemoveContactButton->Click += gcnew System::EventHandler(this, &Messages::removeContactButton_Click);
					panel->Controls->Add(RemoveContactButton);
				}

				this->scrollable_panel->Controls->Add(panel);
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
	private: System::Windows::Forms::Panel^ scrollable_panel;


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
			this->scrollable_panel = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
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
			this->panel1->Controls->Add(this->scrollable_panel);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(3, 51);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(976, 679);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Messages::panel1_Paint);
			// 
			// scrollable_panel
			// 
			this->scrollable_panel->AutoScroll = true;
			this->scrollable_panel->BackColor = System::Drawing::Color::White;
			this->scrollable_panel->Location = System::Drawing::Point(13, 24);
			this->scrollable_panel->Name = L"scrollable_panel";
			this->scrollable_panel->Size = System::Drawing::Size(950, 620);
			this->scrollable_panel->TabIndex = 2;
			this->scrollable_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Messages::scrollable_panel_Paint);
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
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
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
		for (auto it : Login::currentUser->contacts) {
		MessageBox::Show(it.first.ToString(), "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);		}
		this->switchToWelcome = true;
		this->Close();
	}

	public: bool switchToMessage = false;
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
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
		if (!Login::currentUser->recMsg.empty()) {
			generatelabel1ages();
		}
		else
		{
			scrollable_panel->Hide();
		}
		
	}

	private: System::Void scrollable_panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (Login::currentUser->recMsg.size() == 1) {
			scrollable_panel->Hide();
		}

		Button^ buttonA = dynamic_cast<Button^>(sender);
		
			// Convert the Name property (which holds the message id) to int
			int messageId = System::Convert::ToInt32(buttonA->Name);
			Login::currentUser->deleteMessageById(messageId);
			Login::currentUser->saveAllUsers("users.dat");
			generatelabel1ages(); 
	}

	private: System::Void favButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ buttonB = dynamic_cast<Button^>(sender);
		String^ name = buttonB->Name;
		System::String^ id = name->Split('|')[0];
		string id_str = msclr::interop::marshal_as<std::string>(id);
		System::String^ content = name->Split('|')[1];
		string content_str = msclr::interop::marshal_as<std::string>(content);
		System::String^ time = name->Split('|')[2];
		string time_str = msclr::interop::marshal_as<string>(time);
		try {
			::Message msg(content_str, stoi(id_str), Login::currentUser->id);
			Login::currentUser->markMessageAsFavorite(msg);
		}
		catch(exception){
			for (auto it : Login::currentUser->contacts) {
				if (it.second.contactName == id_str) {
					MessageBox::Show(it.second.contactId.ToString(), "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
					::Message msg(content_str, it.second.contactId, Login::currentUser->id);
					Login::currentUser->markMessageAsFavorite(msg);
				}
			}
		}
			MessageBox::Show("Saved As Favorite Successfully", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		
	}



	public: bool switchToChat = false;
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToChat = true; 
		this->Close();
	}


	private: System::Void senderIdLabel_Click(System::Object^ sender, System::EventArgs^ e) {
		Label^ clickedLabel = dynamic_cast<Label^>(sender);
		if (clickedLabel != nullptr) {
			int senderId = System::Convert::ToInt32(clickedLabel->Text);
			if (Login::currentUser->searchContact(senderId)) {
				MessageBox::Show("Contact already exists.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
			 
			 Panel^ parentPanel = dynamic_cast<Panel^>(clickedLabel->Tag);
			
				// Remove the label
				parentPanel->Controls->Remove(clickedLabel);

				// Create TextBox
				TextBox^ textBox = gcnew TextBox();
				textBox->Size = System::Drawing::Size(120, 30);
				textBox->Location = clickedLabel->Location;
				textBox->Text = ""; // Let user enter contact name

				// Store senderId in Tag for later use
				textBox->Tag = clickedLabel->Text;

				// Create Button
				Button^ button = gcnew Button();
				button->Text = "Save";
				button->Size = System::Drawing::Size(60, 30);
				button->Location = System::Drawing::Point(clickedLabel->Location.X + textBox->Width + 10, clickedLabel->Location.Y);

				// Pass both controls as a tuple in the button's Tag for access in the handler
				button->Tag = gcnew Tuple<TextBox^, Panel^>(textBox, parentPanel);

				// Attach click handler
				button->Click += gcnew System::EventHandler(this, &Messages::saveContactButton_Click);

				parentPanel->Controls->Add(textBox);
				parentPanel->Controls->Add(button);
				textBox->BringToFront();
				button->BringToFront();
			
		}
	}


	private: System::Void saveContactButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ saveBtn = dynamic_cast<Button^>(sender);
		if (saveBtn != nullptr) {
			auto tuple = dynamic_cast<Tuple<TextBox^, Panel^>^>(saveBtn->Tag);
			if (tuple != nullptr) {
				TextBox^ textBox = tuple->Item1;
				Panel^ parentPanel = tuple->Item2;
				System::String^ contactName = textBox->Text;
				System::String^ senderIdStr = dynamic_cast<System::String^>(textBox->Tag);

				if (!System::String::IsNullOrWhiteSpace(contactName) && !System::String::IsNullOrWhiteSpace(senderIdStr)) {
					int senderId = System::Convert::ToInt32(senderIdStr);

					// Check again before saving
					if (Login::currentUser->searchContact(senderId)) {
						MessageBox::Show("Contact already exists.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
						parentPanel->Controls->Remove(textBox);
						parentPanel->Controls->Remove(saveBtn);

						Label^ senderIdLabel = gcnew Label();
						senderIdLabel->Text = senderIdStr;
						senderIdLabel->Location = textBox->Location;
						senderIdLabel->AutoSize = true;
						senderIdLabel->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold);
						senderIdLabel->Click += gcnew System::EventHandler(this, &Messages::senderIdLabel_Click);
						senderIdLabel->Tag = parentPanel;
						parentPanel->Controls->Add(senderIdLabel);
						senderIdLabel->BringToFront();
						generatelabel1ages();
						return;

					}
					

					// Create and add the contact
					std::string nameStd = msclr::interop::marshal_as<std::string>(contactName);
					Contact newContact = Contact(nameStd);
					newContact.setContactId(senderId);

					// Count messages from this sender
					int msgCounter = 0;
					for (const auto& msg : Login::currentUser->recMsg) {
						if (msg.getSenderId() == senderId) {
							++msgCounter;
						}
					}
					newContact.msgCount=msgCounter; // Make sure Contact has setMsgCount(int) method

					Login::currentUser->contacts[senderId] = newContact;
					User::saveAllUsers("users.dat");

					// Remove the TextBox and Button
					parentPanel->Controls->Remove(textBox);
					parentPanel->Controls->Remove(saveBtn);


					// Add a new label with the contact name (no click handler)
					Label^ contactNameLabel = gcnew Label();
					contactNameLabel->Text = contactName;
					contactNameLabel->Location = textBox->Location;
					contactNameLabel->AutoSize = true;
					contactNameLabel->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold);
					contactNameLabel->Tag = parentPanel;
					parentPanel->Controls->Add(contactNameLabel);
					contactNameLabel->BringToFront();

					// Add the 3 dot icon button after saving the contact
					Button^ RemoveContactButton = gcnew Button();
					RemoveContactButton->Text = "";
					RemoveContactButton->Size = System::Drawing::Size(40, 40);
					RemoveContactButton->Location = System::Drawing::Point(parentPanel->Width - RemoveContactButton->Width - 10, parentPanel->Height - RemoveContactButton->Height - 10);
					RemoveContactButton->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Right);
					RemoveContactButton->Image = System::Drawing::Image::FromFile("C:\\Users\\20102\\source\\repos\\Saraha-Modifiedddd\\Images\\3 dots icon.jpg");
					RemoveContactButton->ImageAlign = System::Drawing::ContentAlignment::MiddleCenter;
					RemoveContactButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					RemoveContactButton->Tag = gcnew Tuple<int, Panel^>(senderId, parentPanel);
					RemoveContactButton->Click += gcnew System::EventHandler(this, &Messages::removeContactButton_Click);
					parentPanel->Controls->Add(RemoveContactButton);
					RemoveContactButton->BringToFront();

					MessageBox::Show("Contact saved!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Please enter a contact name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}
		generatelabel1ages();
	}
		   
		   

	private: System::Void removeContactButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ btn = dynamic_cast<Button^>(sender);
		if (btn != nullptr) {
			auto tuple = dynamic_cast<Tuple<int, Panel^>^>(btn->Tag);
			if (tuple != nullptr) {
				int senderId = tuple->Item1;
				Panel^ parentPanel = tuple->Item2;

				// Ask for confirmation
				System::Windows::Forms::DialogResult result = MessageBox::Show(
					"Do you want to remove this contact?", "Remove Contact",
					MessageBoxButtons::YesNo, MessageBoxIcon::Question);

				if (result == System::Windows::Forms::DialogResult::Yes) {
					// Remove contact from user
					Login::currentUser->rmcontact(senderId);
					Login::currentUser->saveAllUsers("users.dat");
					// Remove the contact name label and 3-dot button
					Label^ contactNameLabel = nullptr;
					for each (Control ^ ctrl in parentPanel->Controls) {
						Label^ lbl = dynamic_cast<Label^>(ctrl);
						if (lbl != nullptr && lbl->Location == System::Drawing::Point(60, 10)) {
							contactNameLabel = lbl;
							break;
						}
					}
					if (contactNameLabel != nullptr) {
						parentPanel->Controls->Remove(contactNameLabel);
					}
					parentPanel->Controls->Remove(btn);

					// Add senderId label again 
					Label^ senderIdLabel = gcnew Label();
					senderIdLabel->Text = senderId.ToString();
					senderIdLabel->Location = System::Drawing::Point(60, 10);
					senderIdLabel->AutoSize = true;
					senderIdLabel->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold);
					senderIdLabel->Click += gcnew System::EventHandler(this, &Messages::senderIdLabel_Click);
					senderIdLabel->Tag = parentPanel;
					parentPanel->Controls->Add(senderIdLabel);
					senderIdLabel->BringToFront();
				}
				
			}
		}
		generatelabel1ages();
	}


	};
}