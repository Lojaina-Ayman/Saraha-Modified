#pragma once
#include <string>
using namespace std;

class Contact {
    int msgCount = 0;
    string msgID;
    string name;

public:
    Contact(string name);
    void incMsgCount();
    void getMsgCount();
    string getName() const;
    void setName(string name);
    int getMsgID() const;
    void setMsgID(string msgID);
};