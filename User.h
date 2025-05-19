#ifndef USER_H
#define USER_H

#pragma once
#include <iostream>
#include <vector>
#include "Contact.h"
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <functional>

struct comparing {
	bool operator()(const Contact& a, const Contact& b) const {

		if (a.getMsgCount() > b.getMsgCount())
			return true;
		else if (a.getMsgCount() < b.getMsgCount())
			return false;
		else {
			if (a.getName() < b.getName())
				return true;
			else
				return false;
		}
	}
};


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
	stack <Message> undoMsgs; // messages that have been undone
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
	void snd_msg(Message msg);
	void undo_msg();
	void redo_msg();
	void delete_msg(int);
	void viewAllfavoriteMessages();
	bool checkcontactcreationeligibility(int contactid);
	set<Contact, comparing> viewContSorted();

	void serialize(ostream& os) const;
	void deserialize(istream& is);
	void static saveAllUsers(const string& filename);
	void static loadAllUsers(const string& filename);
	list<Message>queueTolist(queue<Message>fav);
	queue<Message>listToqueue(list<Message>fav);

};

#endif