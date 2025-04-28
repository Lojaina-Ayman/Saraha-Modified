#pragma once
#include "user.h"
#include <fstream>
#include <unordered_map>
using namespace std;
class Filec 
{
public:
	Filec();
	void createsave(string,unordered_map<string,User>&);
	//void writedata(string, map<int, User>&);
};

