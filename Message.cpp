#include "Message.h"
#include <iostream>
#include <vector>
Message::Message(string data, int sender, int receiver) {
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

void Message::setContent(string s) { content = s; }
void Message::deleteContent() { content = ""; }
void Message::setSenderId(int i) { senderid = i; }
void Message::setReceiver(int r) { receiver = r; }
#include <iostream>
#include <list>
#include "Message.h"

std::string Message::viewAllMessages(std::list<Message> messages) {
    std::string result;
    for (auto it = messages.rbegin(); it != messages.rend(); ++it) {
        const Message& message = *it;
        result += "Sender ID: " + std::to_string(message.getSenderId()) + "\n";
        result += "Receiver ID: " + std::to_string(message.getReceiver()) + "\n";
        result += "Date: " + message.getDateInText() + "\n";
        result += "Content: " + message.getContent() + "\n";
        result += "------------------------\n";
    }

    return result;
}
