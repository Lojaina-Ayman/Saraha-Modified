#include "Filec.h"
using namespace std;

Filec::Filec() {

}

void Filec::writeUser(string path, unordered_map<int, User>& data) {
	ofstream file(path, ios::trunc);
	if (!file.is_open()) {
        return; 
    }

	for (auto& it : data) {
		file << it.second.toString();
		file << std::endl;
	}
	file.close();
}


void Filec::writeMessage(string path, unordered_map<int, Message>& data) {
	ofstream file(path, ios::trunc);
	if (!file.is_open()) {
        return; 
    }

	for (auto& it : data) {
		file << it.second.tostring();
		file << std::endl;
	}
	file.close();
}

void Filec::writeContact(string path, unordered_map<int, Contact>& data) {
	ofstream file(path, ios::trunc);
	if (!file.is_open()) {
        return; 
    }

	for (auto& it : data) {
		file << it.second.tostring();
		file << std::endl;
	}
	file.close();
}

