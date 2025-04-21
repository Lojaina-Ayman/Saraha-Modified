#include "User.h"
#include <list>
User::User() {
    id = 0;
    username = "";
    pass = "";
    msgCount = 0;
}

User::User(int id, string user, string password, vector<Contact> mycontacts,
    vector<Message> Sendmsg, std::queue<Message> favMsg,
    std::list<Message> sentMsg, std::list<Message> recMsg);
{

    this->id = id;
    username = user;
    pass = password;
    msgCount = 0;

    for (const auto& contact : mycontacts) {
    contacts[contact.getId()] = contact;
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

void User::removeOldestFavoriteMessage() {
    if (!favMsg.empty()) {
        favMsg.pop();
        std::cout << "Oldest favorite message removed." << std::endl;
    }
    else {
        std::cout << "No favorite messages to remove." << std::endl;
    }
}


void User::deleteMessageById(int messageId) {

    for (auto it = sentMsg.begin(); it != sentMsg.end(); ++it) {
        if (it->getMessageId() == messageId) {
            sentMsg.erase(it);
            std::cout << "Message removed from sent messages.\n";
            return;
        }
    }

    for (auto it = recMsg.begin(); it != recMsg.end(); ++it) {
        if (it->getMessageId() == messageId) {
            recMsg.erase(it);
            std::cout << "Message removed from received messages.\n";
            return;
        }
    }

    std::queue<Message> tempQueue;
    bool found = false;
    while (!favMsg.empty()) {
        Message msg = favMsg.front();
        favMsg.pop();
        if (msg.getMessageId() == messageId) {
            found = true;
            std::cout << "Message removed from favorite messages.\n";
            continue;
        }
        tempQueue.push(msg);
    }
    favMsg = tempQueue;

    if (!found) {
        std::cout << "Message with ID " << messageId << " not found in any list.\n";
    }
}


void User::searchContact(int contactId) const {
    auto it = contacts.find(contactId);
    if (it != contacts.end()) {
        std::cout << "Contact Found: " << it->second.getName() << std::endl;
    }
    else {
        std::cout << "Contact NOT FOUND." << std::endl;
    }
}


void User::addContacts(Contact contact) {
    contacts.push_back(contact);
}

void User::rmcontact(int contactId) {
    auto it = contacts.find(contactId);
    if (it != contacts.end()) {
        contacts.erase(it);
        std::cout << "Contact removed successfully.\n";
    }
    else {
        std::cout << "Contact not found.\n";
    }
}


void User::snd_msg(Message msg) {
    Send_msg.push_back(msg);
}
