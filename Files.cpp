#include "User.h"
#include "Files.h"
#include <fstream>

	Files::Files() {
		cout << "files constructor" <<endl;
	}

	vector<Message> Files::filereader() {
		ifstream msgfile("messages.txt");
		if (msgfile.is_open()) {
			string msg;
			while (getline(msgfile,msg)) {
				mylist.push_back(msg);
			}
			msgfile.close();
			for (string message : mylist) {
				string element = "";
				vector<string> elements;
				for (int i = 0; i < message.length(); i++) {
					if (message[i] != ',') {
						element += message[i];
					}
					else {
						//first element is read
						elements.push_back(element);
						element = "";
					}
				}
				//first line in mylist is done //first object
				if (elements.size() >= 3){
					Message	MESSAGE(elements[0], stoi(elements[1]), stoi(elements[2]));
					MESSAGE.generateRandomId();
				    mymessages.push_back(MESSAGE);
			    }
					elements.clear();
			}
			return mymessages;
		}
		else
			cout << "file not found"<<endl;
		 return {};
    }


	/////     in source.cpp try:
	//vector<Message> myvector;
	//Files myclass;
	//myvector = myclass.filereader();
	//for (int i = 0; i < myvector.size(); i++) {
	//	cout << myvector[i].getContent() << endl;
	//}




	vector<Contact> Files::contactfilereader() {
		ifstream contactfile("Contacts.txt");
		if (contactfile.is_open()) {
			mylist.clear();
			mycontacts.clear();

			string contact;
			while (getline(contactfile, contact)) {
				mylist.push_back(contact);
			}
			contactfile.close();

			for (string contacts : mylist) {
				string element = "";
				vector<string> elements;

				for (int i = 0; i < contacts.length(); i++) {
					if (contacts[i] != ',') {
						element += contacts[i];
					}
					else {
						elements.push_back(element);
						element = "";
					}
				}


				if (elements.size() >= 2) {
					Contact c(elements[0]);
					c.setContactId(stoi(elements[1]));
					mycontacts.push_back(c);
				}
			}
			return mycontacts;
		}
		else {
			cout << "file not found";
			return {};
		}
	}
	void Files::saveContacts(const vector<Contact>& contacts) {
		ofstream file("Contacts.txt", ios::trunc); // trunc clears the file
		if (file.is_open()) {
			for (const Contact& c : contacts) {
				file << c.getName() << "," << c.getContactId() << "\n";
			}
			file.close();
			cout << "Contacts saved successfully to Contacts.txt\n";
		}
		else {
			cout << "Failed to open Contacts.txt for writing.\n";
		}
	}




