#include <iostream>
#include "User.h"
using namespace std;


int main() {
    User user;
    Contact contact1("Alice");
    Contact contact2("Bob");

    contact1.incMsgCount();
    contact2.incMsgCount();
    contact2.incMsgCount();

    user.addContacts(contact1);
    user.addContacts(contact2);

    auto sortedContacts = user.viewContSorted();

    for (const auto& contact : sortedContacts) {
        std::cout << "Name: " << contact.getName()
            << ", Messages: " << contact.getMsgCount() << "\n";
    }

    return 0;
}