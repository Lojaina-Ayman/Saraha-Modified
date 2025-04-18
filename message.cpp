#include <string>
#include <vector>
#include <ctime>
using namespace std;

class message {
private:
    string content;
    int senderid;
    int receiver;
    time_t doc;
    string dateintext;

public:
    message(string s, int i,int r) {
        content = s;
        senderid = i;
        receiver = r;
        doc = time(0);
        dateintext = ctime(&doc);
        dateintext.pop_back();
    }

    string getContent() const { return content; }
    int getSenderId() const { return senderid; }
    int getReceiver() const { return receiver; }
    time_t getDoc() const { return doc; }
    string getDateInText() const { return dateintext; }

    void setContent(string s) { content = s; }
	void deleteContent(){content = "";}

	void setSenderId(int i) { senderid = i; }
	void setReceiver(int r) { receiver = r; }

};

