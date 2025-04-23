#include "Contact.h"

Contact::Contact(string name) {
    this->contactName = name;
}

void Contact::incMsgCount() {
    msgCount++;
}

int Contact::getMsgCount() {
    return msgCount;
}

string Contact::getName() const {
    return contactName;
}
void Contact::setName(string name) {
    this->contactName = name;
}
