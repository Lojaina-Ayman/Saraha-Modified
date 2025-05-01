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
			cout << "file not found";
    }


	/////     in source.cpp try:
	//vector<Message> myvector;
	//Files myclass;
	//myvector = myclass.filereader();
	//for (int i = 0; i < myvector.size(); i++) {
	//	cout << myvector[i].getContent() << endl;
	//}





