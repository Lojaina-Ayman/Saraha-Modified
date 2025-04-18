#include "Contact.h"

Contact::Contact(string name) {
    this->name = name;
}

void Contact::incMsgCount() {
    msgCount++;
}