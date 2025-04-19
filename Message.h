#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>
#include <list>
using namespace std;

class Message {
private:
    string content;
    int senderid;
    int receiver;
    time_t doc;
    string dateintext;

public:
    Message(string data, int sender, int receiver);

    string getContent() const;
    int getSenderId() const;
    int getReceiver() const;
    time_t getDoc() const;
    string getDateInText() const;

    void setContent(string s);
    void deleteContent();
    void setSenderId(int i);
    void setReceiver(int r);
    std::string viewAllMessages(std::list<Message> messages);
    };

#endif