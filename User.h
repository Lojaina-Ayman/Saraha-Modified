#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Message.h"
#include "Contact.h"
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
using namespace std;

class User
{
public:
	int id, msgCount;
	string username, pass;
	unordered_map<int, Contact> contacts;
	vector<Message> Send_msg;
	queue<Message> favMsg;
	list<Message> sentMsg;
	list<Message> recMsg;
	stack <Message> undoMsgs; // message that have undone
	static unordered_map<string, User> users;

	User();
	User(int id, string user, string password, vector<Contact> mycontacts,
		vector<Message> Sendmsg, queue<Message> favMsg,
		list<Message> sentMsg, list<Message> recMsg);


	void favorites(vector<string> msg);
	void addContacts(Contact contact);
	void rmcontact(int contactid);
	bool login(string username, string password);
	bool regist(string username, string password);
	void viewMessagesFromContact(int contactId);
	void removeOldestFavoriteMessage();
	void deleteMessageById(int messageId);
	void searchContact(int contactId) const;
	void markMessageAsFavorite(int messageid);
	void reci_msg(vector<string> msg);
	void snd_msg();
	void undo_msg();
	void redo_msg();
	void delete_msg(int);
	void viewAllfavoriteMessages();
	bool checkcontactcreationeligibility(int contactid);
	set<Contact, bool(*)(Contact&, Contact&)> viewContSorted();

};