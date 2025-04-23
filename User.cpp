#include "User.h"

unordered_map<string, User> User::users;

User::User() {
    id = 0;
    username = "";
    password = "";
    msgCount = 0;
}

User::User(int id, string user, string pass, vector<Contact> mycontacts,
    vector<Message> Sendmsg, queue<Message> favMsg,
    list<Message> sentMsg, list<Message> recMsg){

    this->id = id;
    username = user;
    password = pass;
    msgCount = 0;

    for (const auto& contact : mycontacts) {
        contacts[contact.getMsgID()] = contact;
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
        cout << "Oldest favorite message removed." << endl;
    }
    else {
        cout << "No favorite messages to remove." << endl;
    }
}


void User::deleteMessageById(int messageId) {

    for (auto it = sentMsg.begin(); it != sentMsg.end(); ++it) {
        if (it->getMessageId() == messageId) {
            sentMsg.erase(it);
            cout << "Message removed from sent messages.\n";
            return;
        }
    }

    for (auto it = recMsg.begin(); it != recMsg.end(); ++it) {
        if (it->getMessageId() == messageId) {
            recMsg.erase(it);
            cout << "Message removed from received messages.\n";
            return;
        }
    }

    queue<Message> tempQueue;
    bool found = false;
    while (!favMsg.empty()) {
        Message msg = favMsg.front();
        favMsg.pop();
        if (msg.getMessageId() == messageId) {
            found = true;
            cout << "Message removed from favorite messages.\n";
            continue;
        }
        tempQueue.push(msg);
    }
    favMsg = tempQueue;

    if (!found) {
        cout << "Message with ID " << messageId << " not found in any list.\n";
    }
}


void User::searchContact(int contactId) const {
    auto it = contacts.find(contactId);
    if (it != contacts.end()) {
        cout << "Contact Found: " << it->second.getName() << endl;
    }
    else {
        cout << "Contact NOT FOUND." << endl;
    }
}


void User::addContacts(Contact contact) {
    contacts.emplace(contact);
}

void User::rmcontact(int contactId) {
    auto it = contacts.find(contactId);
    if (it != contacts.end()) {
        contacts.erase(it);
        cout << "Contact removed successfully.\n";
    }
    else {
        cout << "Contact not found.\n";
    }
}


void User::snd_msg(Message msg) {
    Send_msg.push_back(msg);
}

bool User::login(string user, string pass) {
    auto it = users.find(user);
    if (it != users.end() && it->second.password == pass) {
        return true;
        // Logged in
    }
    return false;
    // Username or password not found
}

bool User::regist(string user, string pass) {
    if (users.find(user) != users.end()) {
        return false;
        // Username's taken
    }

    User newUser;
    newUser.username = user;
    newUser.password = pass;

    users[user] = newUser;
    return true;
    // Register done
}

void User::viewMessagesFromContact(int contactId) {
    auto contactIt = contacts.find(contactId);
    if (contactIt == contacts.end()) {
        return;
        // Contact not found
    }

    Contact& contact = contactIt->second;
    cout << "Messages with " << contact.getName() << ":\n";

    bool messagesFound = false;
    for (const auto& msg : sentMsg) {
        if (msg.getReceiver() == contactId) {
            messagesFound = true;
            // View messages
        }
    }

    if (!messagesFound) {
        // This contact has no messages
    }
}

void User::markMessageAsFavorite(int messageId) {
    for (auto& msg : sentMsg) {
        if (msg.getMessageId() == messageId) {
            favMsg.push(msg);
        }
    }
}
