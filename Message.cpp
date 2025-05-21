#include "Message.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

Message::Message()
    : messageid(0), content(""), senderid(0), receiver(0), dateintext("") {
}
Message::Message(string data, int sender, int receiver) {
    messageid = generateRandomId();
    content = data;
    senderid = sender;
    this->receiver = receiver;
    doc = time(0);  // Current timestamp
    MsgTime();
}


string Message::getContent() const { return content; }
int Message::getSenderId() const { return senderid; }
int Message::getReceiver() const { return receiver; }
time_t Message::getDoc() const { return doc; }
string Message::getDateInText() const { return dateintext; }
int Message::getMessageId() const { return messageid; }

void Message::setContent(string s) { content = s; }
void Message::deleteContent() { content = ""; }
void Message::setSenderId(int i) { senderid = i; }
void Message::setReceiver(int r) { receiver = r; }


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


void Message::serialize(ostream& os) const {
    os << "[MessageID]\n" << messageid << '\n';
    os << "[SenderID]\n" << senderid << '\n';
    os << "[ReceiverID]\n" << receiver << '\n';
    os << "[MsgTime]\n" << timeStr << '\n';
    os << "[DateText]\n" << dateStr << '\n';
    os << "[Content]\n" << content << '\n';
}

void Message::deserialize(istream& is) {
    string label;

    getline(is, label); // [MessageID]
    is >> messageid;
    is.ignore();

    getline(is, label); // [SenderID]
    is >> senderid;
    is.ignore();

    getline(is, label); // [ReceiverID]
    is >> receiver;
    is.ignore();

    getline(is, label); // [TimeText]
    getline(is, timeStr);

    getline(is, label); // [DateText]
    getline(is, dateStr);

    getline(is, label); // [Content]
    getline(is, content);
}



void Message::MsgTime() {

    struct tm timeInfo;
    localtime_s(&timeInfo, &doc);  // Windows-safe version

    // Format date (e.g., "2023-05-10")
    char dateBuffer[20];
    strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", &timeInfo);
    dateStr = dateBuffer;  // Store as a member variable


    char timeBuffer[20];
    strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", &timeInfo);
    timeStr = timeBuffer;  // Store as a member variable


    dateintext = dateStr + " " + timeStr;
}