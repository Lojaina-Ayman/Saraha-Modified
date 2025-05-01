#pragma once
#include <vector>
#include <list>
#include "User.h"
#include <string>
#include "Message.h"
#include "Contact.h"
class Files {
	list<string> mylist;
	vector<Message> mymessages;
	vector<Contact> mycontacts;
public:
	Files();
	vector<Message> filereader();
	vector<Contact>contactfilereader();
	void saveContacts(const vector<Contact>& contacts);
};
