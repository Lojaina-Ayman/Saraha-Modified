#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
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
	std::list<Message> favMsg;
	std::list<Message> sentMsg;
	std::list<Message> recMsg;

	User();
	User(int id, string user, string password, vector<Contact> mycontacts,
		vector<Message> Sendmsg, std::list<Message> favMsg,
		std::list<Message> sentMsg, std::list<Message> recMsg);


	void reci_msg(vector<string> msg);
	void favorites(vector<string> msg);
	void addContacts(Contact contact);
	void rmcontact(string contactid);
	void snd_msg(Message msg);


};