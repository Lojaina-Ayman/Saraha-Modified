#pragma once
#include <string>
using namespace std;

class Contact
{
	int msgCount;
	string msgID, name;

public:
	Contact(string name);
	void incMsgCount();
};
