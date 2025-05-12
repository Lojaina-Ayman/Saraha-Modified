#include "Contact.h"
#include <fstream>

Contact::Contact(string name) {
    this->contactName = name;
    this->contactId = msgCount + 1;
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




void Contact::serialize(ostream& os) const {
    // os << "[ContactID]\n" << contactId << '\n';
    os << "[ContactName]\n" << contactName << '\n';
    // os << "[MsgCount]\n" << msgCount << '\n';

    os << "[MessageCount]\n" << messages.size() << '\n';
    for (const auto& msg : messages) {
        os << "[Message]\n";
        msg.serialize(os);
    }
}

void Contact::deserialize(istream& is) {
    string label;

    /* getline(is, label); // [ContactID]
     is >> contactId;
     is.ignore();*/

    getline(is, label); // [ContactName]
    getline(is, contactName);
    /*
    getline(is, label); // [MsgCount]
    is >> msgCount;
    is.ignore();*/

    getline(is, label); // [MessageCount]
    size_t count;
    is >> count;
    is.ignore();

    messages.clear();
    for (size_t i = 0; i < count; ++i) {
        getline(is, label); // [Message]
        Message msg;
        msg.deserialize(is);
        messages.push_back(msg);
    }
}

