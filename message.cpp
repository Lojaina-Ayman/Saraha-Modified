#include "Message.h"

Message::Message(string s, int i, int r) {
    content = s;
    senderid = i;
    receiver = r;
    doc = time(0);

    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &doc);
    dateintext = buffer;
    dateintext.pop_back(); // remove trailing newline
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
