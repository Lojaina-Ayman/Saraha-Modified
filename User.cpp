#include "User.h"

User::User() {
    id = 0;
    username = "";
    pass = "";
    msgCount = 0;
}

User::User(int id, string user, string password, vector<Contact> mycontacts,
    vector<Message> Sendmsg, linkedList<Message> favMsg,
    linkedList<Message> sentMsg, linkedList<Message> recMsg) {

    this->id = id;
    username = user;
    pass = password;
    msgCount = 0;

    for (const auto& contact : mycontacts) {
        contacts.push_back(contact);
    }

    for (const auto& msg : Sendmsg) {
        Send_msg.push_back(msg);
    }

    this->favMsg = favMsg;
    this->sentMsg = sentMsg;
    this->recMsg = recMsg;
}

void User::reci_msg(vector<string> msg) {
    cout << "Received Messages:\n";
    for (int i = msgCount; i < msg.size(); i++) {
        cout << msg[i] << endl;
        msgCount++;
    }
}

void User::favorites(vector<string> msg) {
    cout << "Your Favorites Messages:\n";
    for (const auto& m : msg) {
        cout << m << endl;
    }
}

void User::addContacts(Contact contact) {
    contacts.push_back(contact);
}

void User::rmcontact(string contactid) {
    // To be implemented
}

void User::snd_msg(Message msg) {
    Send_msg.push_back(msg);
}
