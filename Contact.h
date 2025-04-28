#pragma once
#include "Message.h"
#include "User.h"
using namespace std;

class Contact {
protected:
    int msgCount = 0;
    string contactName="";
    int contactId=0;
    list<Message> messages = {};
public:
    Contact() = default;
    Contact(const Contact&) = default;
    Contact& operator=(const Contact&) = default;
    Contact (string name);
    Contact (string , int );
    void incMsgCount();
    int getMsgCount() const;
    string getName() const;
    void setName(string name);
    int getContactId() const;
    void setContactId(int id);
    void addMessage(const Message& message);
    void removeMessage(int messageId);
    string tostring();
};