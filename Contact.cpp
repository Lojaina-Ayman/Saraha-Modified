#include "Contact.h"


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
