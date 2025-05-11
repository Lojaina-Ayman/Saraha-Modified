#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>
#include <list>
using namespace std;

class Message {
public:
    string content;
    int messageid;
    int senderid;
    int receiver;
    time_t doc;
    string dateintext;
    string dateStr;
    string timeStr;

public:
    Message();
    Message(string data, int sender, int receiver);
    string getContent() const;
    int getSenderId() const;
    int getReceiver() const;
    int getMessageId() const;
    time_t getDoc() const;
    string getDateInText() const;

    void setContent(string s);
    void deleteContent();
    void setSenderId(int i);
    void setReceiver(int r);
    string returnAllMessages(list<Message> messages);
    int generateRandomId();
    void MsgTime();
    void serialize(ostream& os) const;
    void deserialize(istream& is);
};

#endif