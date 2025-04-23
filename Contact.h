#pragma once
#include "Message.h"
using namespace std;

class Contact {
    int msgCount = 0;
    string contactName;
    int contactId;
    list<Message> messages;


public:
    Contact(string name);
    void incMsgCount();
    int getMsgCount();
    string getName() const;
    void setName(string name);
    int getContactId() const;
    void setContactId(int id);
    void addMessage(const Message& message);
    void removeMessage(int messageId);
};