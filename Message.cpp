#include "Message.h"
#include <iostream>
#include <vector>
Message::Message(string data, int sender, int receiver) {
    content = data;
    senderid = sender;
    receiver = receiver;
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
void Message::viewAllMessages(std::list<Message> messages) {
    for (const auto& message : messages) {
        std::cout << "Sender ID: " << message.getSenderId() << std::endl;
        std::cout << "Receiver ID: " << message.getReceiver() << std::endl;
        std::cout << "Date: " << message.getDateInText() << std::endl;
        std::cout << "Content: " << message.getContent() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}