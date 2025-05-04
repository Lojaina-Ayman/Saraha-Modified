#include "User.h"
#include <algorithm> // for std::find_if

unordered_map<string, User> User::users;

User::User() {
    id = 0;
    username = "";
    pass = "";
    msgCount = 0;
}

User::User(int id, string user, string pass, vector<Contact> mycontacts,
    vector<Message> Sendmsg, queue<Message> favMsg,
    list<Message> sentMsg, list<Message> recMsg) {

    this->id = id;
    username = user;
    this->pass = pass;
    msgCount = 0;

    for (const auto& contact : mycontacts) {
        contacts[contact.getContactId()] = contact;
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
    if (checkcontactcreationeligibility(contact.getContactId()))
    {
        contacts.emplace(contact.getContactId(), contact);
    }
    else 
        cout << "No Message history between "<<username <<" and "<<contact.getContactId()<<"; cannot add contact" << endl;// we can't use names yet
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

void User::snd_msg() {
    string msgData;
    cout << "Enter Message ";
    getline(cin, msgData);
    int receiverId;
    cout << "Enter receiver ID ";
    cin >> receiverId;
    cin.ignore();
    Message msg = Message(msgData, this->id, receiverId);
    cout << "Your Message Id is " << msg.getMessageId() << endl;
    this->sentMsg.push_back(msg);
    int option;
    cout << "Enter 1 to undo the last sent message " << endl;
    cout << "Enter 2 to redo the last sent message " << endl;
    cout << "Enter 3 to delete any message " << endl;
    cout << "Enter 4 to do nothing " << endl;
    cout << "Enter 5 to enter another message " << endl;
    cin >> option;
    cin.ignore();

    //Receiver ID Doesn't exist condition (To Be Implemented)
    while (option != 4 && option != 5) {
        if (option == 1) { undo_msg(); }
        else if (option == 2) { redo_msg(); }
        else if (option == 3) {
            int MessId;
            cout << "Enter Message Id ";
            cin >> MessId;
            cin.ignore();
            delete_msg(MessId);
        }
        else { return; }
        cout << "Enter 1 to undo the last sent message " << endl;
        cout << "Enter 2 to redo the last sent message " << endl;
        cout << "Enter 3 to delete any message " << endl;
        cout << "Enter 4 to do nothing " << endl;
        cout << "Enter 5 to enter another message " << endl;
        cin >> option;
        cin.ignore();
    }
    if (option == 5) { snd_msg(); }

}

void User::undo_msg() {

    undoMsgs.push(this->sentMsg.back()); //put the last element from the list in a stack
    this->sentMsg.pop_back();//remove message from list
    cout << "Undo is done \n";
}

void User::redo_msg() {
    if (undoMsgs.empty()) {
        cout << "No Messages have been undone";
    }
    else {
        this->sentMsg.push_back(undoMsgs.top());//put the messge back to the list
        cout << undoMsgs.top().getContent() << endl;
        undoMsgs.pop(); //remove the messge from the stack
    }
}

void User::delete_msg(int msgID) {
    auto it = find_if(sentMsg.begin(), sentMsg.end(),
        [msgID](const Message& msg) {
            return msg.getMessageId() == msgID;
        });

    if (it != sentMsg.end()) {
        cout << "Found: " << it->getMessageId() << endl;

        undoMsgs.push(*it);
        sentMsg.erase(it);
        cout << "Deleting completed";
    }
    else {

        cout << "Not found." << endl;
    }
}

bool User::login(string user, string pass) {
    auto it = users.find(user);
    if (it != users.end() && it->second.pass == pass) {
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
    newUser.pass = pass;

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

void User::viewAllfavoriteMessages() {
    queue <Message> helperqueue = favMsg;
    Message iteration;
    string output;
    if (!helperqueue.empty()) {
        cout << "here are " << username << "'s Favorite Messsages" << endl;
        while (!helperqueue.empty()) {
            iteration = helperqueue.front();
            output += "Message ID: " + to_string(iteration.getMessageId()) + "\n";
            output += "Date: " + iteration.getDateInText() + "\n";
            output += "Content: " + iteration.getContent() + "\n";
            output += "------------------------\n";
        }
        cout << output;
    }
    else {
        cout << "No favorite messages exist for " << username << endl;
    }

}

bool User::checkcontactcreationeligibility(int contactid) {
    list<Message> iteree = recMsg;
    for (const Message msg : iteree) {
        if (msg.getReceiver() == contactid)
            return true;
    }
    return false;
}

bool User::searchcont(const Contact& a, const Contact& b) {
    if (a.getMsgCount() != b.getMsgCount()) {
        return a.getMsgCount() > b.getMsgCount(); // Sort by message count (descending)
    }
    return a.getName() < b.getName(); // Sort by name (ascending)
}

set<Contact, function<bool(const Contact&, const Contact&)>> User::viewContSorted() {
    auto comparator = [](const Contact& a, const Contact& b) -> bool {
        if (a.getMsgCount() != b.getMsgCount()) {
            return a.getMsgCount() > b.getMsgCount(); // Sort by message count (descending)
        }
        return a.getName() < b.getName(); // Sort by name (ascending)
        };

    set<Contact, function<bool(const Contact&, const Contact&)>> sortedContacts(comparator);

    for (const auto& entry : contacts) {
        const Contact& contact = entry.second; // Access the Contact object
        sortedContacts.insert(contact);       // Insert the Contact object into the set
    }

    return sortedContacts;
}
