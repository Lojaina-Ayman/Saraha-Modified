#include "Filec.h"
using namespace std;

Filec::Filec() {

}

void Filec::createsave(string path, unordered_map<string, User>& data) {
	string alldata = "", line = "";
	fstream file(path, ios::app);
	size_t length;
	//for (auto& it : data) {
	//	file << it.second.toString();
	//}
	file << "hi";
	file.close();
}
