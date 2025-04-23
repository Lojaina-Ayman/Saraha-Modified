#pragma once
#include <string>
#include "Message.h"
using namespace std;

class Contact : public Message {
    int msgCount = 0;
    string contactName;

public:
    Contact(string name);
    void incMsgCount();
    int getMsgCount();
    string getName() const;
    void setName(string name);
    int getMsgID() const;
    void setMsgID(int msgID);
};