#include "User.h"
#include <algorithm> 
#include <fstream>

unordered_map<string, User> User::users;

User::User() {
    id = 0;
    username = "";
    pass = "";
    msgCount = 0;

    // Testing

    recMsg.push_back(Message("AHlan", 22, 33));
    favMsg.push(Message("Hello My name is youssef", 1, 2));
    favMsg.push(Message("Hello My name is Ahmed", 1, 2));
    favMsg.push(Message("Hello My name is Ali", 1, 2));
    favMsg.push(Message("Hello My name is Aya", 1, 2));
    favMsg.push(Message("Hello My name is Hamdy", 1, 2));
    recMsg.push_back(Message("HELLOOOO", 23, 0));
    recMsg.push_back(Message("HELLOOOO", 23, 0));
    recMsg.push_back(Message("dasdasdas", 22, 0));
    recMsg.push_back(Message("ssssssssssss", 22, 0));
    recMsg.push_back(Message("zzzzzzzzzzzz", 22, 0));

    sentMsg.push_back(Message("To hell with Archi", 1, 2));
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
int User::getId() {
    return this->id;
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

bool User::searchContact(int contactId) const {
    auto it = contacts.find(contactId);
    if (it != contacts.end()) {
        return true;
    }
    else {
        return false;
    }

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
    this->sentMsg.push_back(msg);
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



void User::viewMessagesFromContact(int id) {
    auto it = contacts.find(id);
    if (it == contacts.end()) {
        return;
        // Contact not found
    }

    Contact& contact = it->second;
    cout << "Messages with " << contact.getName() << ":\n";

    bool msgFound = false;
    for (const auto& msg : sentMsg) {
        if (msg.getReceiver() == id) {
            msgFound = true;
            // View messages
        }
    }

    if (!msgFound) {
        // This contact has no messages
    }
}

void User::markMessageAsFavorite(Message msg) {
    favMsg.push(msg);
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




vector<Contact> User::viewContactsSortedByMsgCount() const {
    vector<Contact> sorted;
    for (const auto& pair : contacts)
        sorted.push_back(pair.second);

    sort(sorted.begin(), sorted.end(), CompareByMsgCount());
    return sorted;
}




void User::serialize(ostream& os) const {
    os << "[Username]\n" << username << '\n';
    os << "[Password]\n" << pass << '\n';
    os << "[ID]\n" << id << '\n';
    os << "[MsgCount]\n" << msgCount << '\n';

    os << "[ContactsCount]\n" << contacts.size() << '\n';
    for (auto it : contacts) {
        os << "[ContactID]\n" << it.first << '\n';
        it.second.serialize(os);
    }

    os << "[SendMsgCount]\n" << Send_msg.size() << '\n';
    for (const auto& msg : Send_msg) {
        os << "[SendMessage]\n";
        msg.serialize(os);
    }

    os << "[FavMsgCount]\n" << favMsg.size() << '\n';
    auto favCopy = favMsg;
    while (!favCopy.empty()) {
        os << "[FavMessage]\n";
        favCopy.front().serialize(os);
        favCopy.pop();
    }

    os << "[SentMsgCount]\n" << sentMsg.size() << '\n';
    for (const auto& msg : sentMsg) {
        os << "[SentMessage]\n";
        msg.serialize(os);
    }

    os << "[RecMsgCount]\n" << recMsg.size() << '\n';
    for (const auto& msg : recMsg) {
        os << "[RecMessage]\n";
        msg.serialize(os);
    }

    stack<Message> undoCopy = undoMsgs;
    vector<Message> stackOrder;
    while (!undoCopy.empty()) {
        stackOrder.push_back(undoCopy.top());
        undoCopy.pop();
    }
    os << "[UndoMsgCount]\n" << stackOrder.size() << '\n';
    for (auto it = stackOrder.rbegin(); it != stackOrder.rend(); ++it) {
        os << "[UndoMessage]\n";
        it->serialize(os);
    }
}


void User::deserialize(istream& is) {
    string label;

    getline(is, label); // [Username]
    getline(is, username);

    getline(is, label); // [Password]
    getline(is, pass);

    getline(is, label); // [ID]
    is >> id; is.ignore();

    getline(is, label); // [MsgCount]
    is >> msgCount; is.ignore();

    size_t count;
    getline(is, label); // [ContactsCount]
    is >> count; is.ignore();
    contacts.clear();
    for (size_t i = 0; i < count; ++i) {
        int cid;
        getline(is, label); // [ContactID]
        is >> cid; is.ignore();
        Contact c;
        c.deserialize(is);
        contacts[cid] = c;
    }

    getline(is, label); // [SendMsgCount]
    is >> count; is.ignore();
    Send_msg.clear();
    for (size_t i = 0; i < count; ++i) {
        getline(is, label); // [SendMessage]
        Message m;
        m.deserialize(is);
        Send_msg.push_back(m);
    }

    getline(is, label); // [FavMsgCount]
    is >> count; is.ignore();
    while (!favMsg.empty()) favMsg.pop();
    for (size_t i = 0; i < count; ++i) {
        getline(is, label); // [FavMessage]
        Message m;
        m.deserialize(is);
        favMsg.push(m);
    }

    getline(is, label); // [SentMsgCount]
    is >> count; is.ignore();
    sentMsg.clear();
    for (size_t i = 0; i < count; ++i) {
        getline(is, label); // [SentMessage]
        Message m;
        m.deserialize(is);
        sentMsg.push_back(m);
    }

    getline(is, label); // [RecMsgCount]
    is >> count; is.ignore();
    recMsg.clear();
    for (size_t i = 0; i < count; ++i) {
        getline(is, label); // [RecMessage]
        Message m;
        m.deserialize(is);
        recMsg.push_back(m);
    }

    getline(is, label); // [UndoMsgCount]
    is >> count; is.ignore();
    vector<Message> temp;
    for (size_t i = 0; i < count; ++i) {
        getline(is, label); // [UndoMessage]
        Message m;
        m.deserialize(is);
        temp.push_back(m);
    }
    while (!undoMsgs.empty()) undoMsgs.pop();
    for (auto it = temp.rbegin(); it != temp.rend(); ++it)
        undoMsgs.push(*it);
}


//Write
void User::saveAllUsers(const string& filename) {
    ofstream ofs(filename);
    if (!ofs) {
        cerr << "Failed to open file for saving users.\n";
        return;
    }

    ofs << users.size() << '\n';
    for (auto& it : users) {
        it.second.serialize(ofs);
    }
}

//Read
void User::loadAllUsers(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "User file not found. Starting with empty user list.\n";
        users.clear();
        return;
    }

    // Handle empty file
    ifs.seekg(0, ios::end);
    if (ifs.tellg() == 0) {
        ifs.close();
        users.clear();
        return;
    }
    ifs.seekg(0, ios::beg); // Rewind

    size_t userCount;
    if (!(ifs >> userCount)) {
        cerr << "Invalid file format.\n";
        users.clear();
        return;
    }
    ifs.ignore(); // Skip newline


    for (size_t i = 0; i < userCount; ++i) {
        User usr;
        usr.deserialize(ifs);
        if (ifs.fail()) {
            cerr << "Failed to deserialize a user.\n";
            continue;
        }
        users[usr.username] = usr;
    }
}


list<Message> User::queueTolist(queue<Message>fav) {
    list<Message>output;
    while (!fav.empty()) {
        output.push_front(fav.front());
        fav.pop();
    }
    return output;
}

queue<Message> User::listToqueue(list<Message>fav) {
    queue<Message>favsqueue;
    for (auto it : fav) {
        favsqueue.push(it);
    }
    return favsqueue;
}
