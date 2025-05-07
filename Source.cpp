#include "User.h"
#include "Files.h"


int main() {
    Files myclass;

    // Create and save some contacts
    vector<Contact> contacts;
    Contact c1("Alice"); c1.setContactId(121); 
    Contact c2("Bob");   c2.setContactId(1002);
    contacts.push_back(c1);
    contacts.push_back(c2);

    myclass.saveContacts(contacts); //  Save to file

    // Read them back
    vector<Contact> loadedContacts = myclass.contactfilereader();
    for (const Contact& c : loadedContacts) {
        cout << "Name: " << c.getName() << ", ID: " << c.getContactId() << endl;
    }
    

     vector<Message> myvector;
    myvector = myclass.filereader();
    for (int i = 0; i < myvector.size(); i++) {
    	cout << myvector[i].getContent() << endl;
    }


    User temp;
    temp.regist("john_doe", "password123");
    User user1 = User::users["john_doe"];
    user1.id = 1;

    if (user1.login("john_doe", "password123")) {
        cout << "Login successful!" << endl;
    }

    // Create a contact and simulate prior message from them
    Contact contact1("Alice");
    contact1.setContactId(1001);
    contact1.incMsgCount();
    cout << "Contact Created: " << contact1.getName() << " with ID " << contact1.getContactId() << endl;

    // Simulate received message (to pass contact eligibility check)
    user1.recMsg.push_back(Message("Hi from Alicce!", 1001, user1.id));

    // Add contact now that eligibility is met
    user1.addContacts(contact1);

    // Send message to contact
    Message msg1("Hello Alice!", user1.id, 1001);
    user1.sentMsg.push_back(msg1);
    cout << "Sent message ID: " << msg1.getMessageId() << endl;
    
    // Undo, redo
    user1.undo_msg();
    user1.redo_msg();

    // Favorite message
    user1.markMessageAsFavorite(msg1.getMessageId());
    user1.viewAllfavoriteMessages();
    user1.removeOldestFavoriteMessage();
    user1.viewAllfavoriteMessages();

    // Contact search and removal
    user1.searchContact(contact1.getContactId());
    user1.rmcontact(contact1.getContactId());
    return 0;
}