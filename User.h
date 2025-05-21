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

struct CompareByMsgCount {
	bool operator()(const Contact& a, const Contact& b) const {
		return a.getMsgCount() > b.getMsgCount(); 
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

	int getId();
	void favorites(vector<string> msg);
	void rmcontact(int contactid);
	
	void viewMessagesFromContact(int contactId);
	void removeOldestFavoriteMessage();
	void deleteMessageById(int messageId);
	bool searchContact(int contactId) const;
	void markMessageAsFavorite(Message msg);
	void reci_msg(vector<string> msg);
	void snd_msg(Message msg);
	void undo_msg();
	void redo_msg();
	void delete_msg(int);
	void viewAllfavoriteMessages();
	vector<Contact> viewContactsSortedByMsgCount() const;
	void serialize(ostream& os) const;
	void deserialize(istream& is);
	void static saveAllUsers(const string& filename);
	void static loadAllUsers(const string& filename);
	list<Message>queueTolist(queue<Message>fav);
	queue<Message>listToqueue(list<Message>fav);

};

#endif