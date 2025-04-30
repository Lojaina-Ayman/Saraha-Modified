#include <iostream>
#include "User.h"
#include "Filec.h"
using namespace std;


int main() {
	/*int id, string user, string pass, vector<Contact> mycontacts, queue<Message> favMsg,
    list<Message> sentMsg, list<Message> recMsg*/
	string garbage;
	int id1 = 1, id2 = 2;
	string user1 = "Alice",user2 ="Bob",pass1="password123",pass2="securepass";
	unordered_map<int,Contact> contact1,contact2;
	Contact c1 = Contact("Alice", 1), c2=Contact("Bob", 2);
	contact1.insert({ 1,c2 });
	contact2.insert({ 1,c1 });
	queue<Message> fav;
	list<Message> al;
	User u1 = User(id1, user1,pass1, contact1, fav, al, al),u2=User(id2, user2, pass2, contact2, fav, al, al);

u1.regist(u1.username, u1.pass);
u2.regist(u2.username, u2.pass);

u1.snd_msg();
u2.snd_msg();
cin >> garbage;
Filec fof;
fof.createsave("filesys/unload.txt", User().users);
return 0;
}