#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>
#include <list>
using namespace std;

class Message {
private:
    string content;
    int messageid;
    int senderid;
    int receiver;
    time_t doc;
    string dateintext;
    bool isFavorite = false;

public:
    Message(string data, int sender, int receiver);
    string getContent() const;
    int getSenderId() const;
    int getReceiver() const;
    int getMessageId() const;
    bool getIsFavorite() const;
    time_t getDoc() const;
    string getDateInText() const;

    void setContent(string s);
    void deleteContent();
    void setSenderId(int i);
    void setReceiver(int r);
    std::string viewAllMessages(std::list<Message> messages);
    void setFavorite(int messageid);
    int generateRandomId();
    };

#endif