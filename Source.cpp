#include <iostream>
#include "User.h"
#include "Filec.h"
using namespace std;


int main() {
    
    //Contact contact1("Alice");
    //Contact contact2("Bob");
    //vector<Contact> vector;
    ////User user=User(1,"john","smith",vector,);

    //contact1.incMsgCount();
    //contact2.incMsgCount();
    //contact2.incMsgCount();

    //user.addContacts(contact1);
    //user.addContacts(contact2);

    //auto sortedContacts = user.viewContSorted();

    //for (const auto& contact : sortedContacts) {
    //    std::cout << "Name: " << contact.getName()
    //        << ", Messages: " << contact.getMsgCount() << "\n";
    //}
    
//int id, string user, string password, vector<Contact> mycontacts,
//vector<Message> Sendmsg, queue<Message> favMsg,
//list<Message> sentMsg, list<Message> recMsg

    User sender; //(1, "Alice", "password123")
    User receiver; //(2, "Bob", "securepass")
    sender.login("Alice", "password123");
    sender.id = 1;
    receiver.login("Bob", "securepass");
    receiver.id = 2;
    Contact c1(sender.username,sender.id);
    Contact c2(receiver);
    sender.snd_msg();
    receiver.snd_msg();
    auto it = sender.recMsg.begin();
    sender.markMessageAsFavorite(it->getMessageId());
    it = receiver.recMsg.begin();
    sender.markMessageAsFavorite(it->getMessageId());
    sender.addContactsf(c2);
    receiver.addContactsf(c1);
    Filec fof;
    fof.createsave("filesys/unload.txt",User().users );
    return 0;
}