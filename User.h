#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "linkedList.h"
#include "Message.h"
#include "Contact.h"
using namespace std;

class User
{
public:
	int id, msgCount;
	string username;
	string pass;
	vector<Contact> contacts;
	vector<Message> Send_msg;
	linkedList<Message> favMsg;
	linkedList<Message> sentMsg;
	linkedList<Message> recMsg;

	User();
	User(int id, string user, string password, vector<Contact> mycontacts,
		vector<Message> Sendmsg, linkedList<Message> favMsg,
		linkedList<Message> sentMsg, linkedList<Message> recMsg);


	void reci_msg(vector<string> msg);
	void favorites(vector<string> msg);
	void addContacts(Contact contact);
	void rmcontact(string contactid);
	void snd_msg(Message msg);


};