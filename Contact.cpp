#include "Contact.h"

Contact::Contact(string name) {
    this->contactName = name;
    this->contactId = msgCount + 1;
}

Contact::Contact(string username,int id) {
    this->contactName = username;
    this->contactId = id;
}

void Contact::incMsgCount() {
    msgCount++;
}

int Contact::getMsgCount() const {
    return msgCount;
}

string Contact::getName() const {
    return contactName;
}
void Contact::setName(string name) {
    this->contactName = name;
}

int Contact::getContactId() const {
    return contactId;
}
void Contact::setContactId(int id) {
    this->contactId = id;
}
void Contact::addMessage(const Message& message) {
    messages.push_back(message);
}
void Contact::removeMessage(int messageId) {
    messages.remove_if([messageId](const Message& msg) { return msg.getMessageId() == messageId; });
}
string Contact::tostring() {
    /*int int msgCount = 0;
    string contactName;
    int contactId;
    list<Message> messages;*/
    string word="";
    word += to_string(msgCount);
    word += ",";
    word += contactName;
    word += ",";
    word += to_string(contactId);
    word += ",";
    word += to_string((int)messages.size());
    word += "(";
    for (auto it : messages)
    {
        word += it.tostring();
    }
    word += ")";
    return word;
}
