#include <iostream>
#include "User.h"
using namespace std;

int main() {
    // Create contacts
    vector<Contact> contacts = {
        Contact("Alice"),
        Contact("Bob")
    };

    // Create messages
    vector<Message> sendMsgs = {
        Message("Hello Alice!", 1, 2),
        Message("Hi Bob!", 1, 3)
    };

    linkedList<Message> favMsgs;
    favMsgs.insertAtBeginning(Message("Favorite 1", 1, 4));
    favMsgs.insertAtBeginning(Message("Favorite 2", 1, 5));

    linkedList<Message> sentMsgs;
    sentMsgs.insertAtBeginning(Message("Sent to Alice", 1, 2));

    linkedList<Message> recMsgs;
    recMsgs.insertAtBeginning(Message("Received from Bob", 3, 1));

    // Create the User object
    User user1(1, "john_doe", "securepass123", contacts, sendMsgs, favMsgs, sentMsgs, recMsgs);

    return 0;
}