#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>

class message {
private:
    std::string content;
    int senderid;
    int receiver;
    std::time_t doc;
    std::string dateintext;

public:
    message(std::string s, int i, int r);

    std::string getContent() const;
    int getSenderId() const;
    int getReceiver() const;
    std::time_t getDoc() const;
    std::string getDateInText() const;

    void setContent(std::string s);
    void deleteContent();
    void setSenderId(int i);
    void setReceiver(int r);
};

#endif