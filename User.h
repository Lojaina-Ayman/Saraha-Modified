#ifndef USER_H
#define USER_H

#pragma once
#include <iostream>
#include <vector>
#include "Message.h"
#include "Contact.h"
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <functional>

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
	// Comparator function
	bool searchcont(const Contact& a, const Contact& b);

	// Function to return sorted contacts
	set<Contact, function<bool(const Contact&, const Contact&)>> viewContSorted();

};

#endif