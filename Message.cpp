#include "Message.h"
#include <iostream>
#include <vector>
#include <set>

Message::Message(string data, int sender, int receiver) {
    messageid = generateRandomId();
    content = data;
    senderid = sender;
    this->receiver = receiver;
    doc = time(0);

    char buffer[26];
    ctime_r(&doc, buffer);
    dateintext = buffer;
    dateintext.pop_back();
}

string Message::getContent() const { return content; }
int Message::getSenderId() const { return senderid; }
int Message::getReceiver() const { return receiver; }
time_t Message::getDoc() const { return doc; }
string Message::getDateInText() const { return dateintext; }
int Message::getMessageId() const { return messageid; }
bool Message::getIsFavorite() const { return isFavorite; }

void Message::setContent(string s) { content = s; }
void Message::deleteContent() { content = ""; }
void Message::setSenderId(int i) { senderid = i; }
void Message::setReceiver(int r) { receiver = r; }
void Message::setFavorite(int messageid) {
    this->messageid = messageid;
    isFavorite = true; // In the main function, make a queue and have it iterate through the messages and enqueue any message that is marked as favorite
}

set<int> usedIDs;
int Message::generateRandomId() {
    srand(time(0));  
    int randomId;
    do {
        randomId = rand() % 9000000 + 1000000;  // generate number from 1,000,000 to 9,999,999
    } while (usedIDs.find(randomId) != usedIDs.end());  // check if id exists

    usedIDs.insert(randomId);
    return randomId;
}


#include <iostream>
#include <list>
#include "Message.h"

string Message::viewAllMessages(list<Message> messages) {
    string result;
    for (auto it = messages.rbegin(); it != messages.rend(); ++it) {
        const Message& message = *it;
        result += "Message ID: " + to_string(message.getMessageId()) + "\n";
        result += "Date: " + message.getDateInText() + "\n";
        result += "Content: " + message.getContent() + "\n";
        result += "------------------------\n";
    }

    return result;
}