#pragma once
#include "User.h"
#include <fstream>
#include <unordered_map>
using namespace std;
class Filec
{
public:
	Filec();
	void writeUser(string, unordered_map<int, User>&);
	void writeMessage(string path, unordered_map<int, Message>& data);
	void writeContact(string path, unordered_map<int, Contact>& data);

	
};