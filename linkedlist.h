#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cassert>

template <class T>
struct Node {
    T data;
    Node<T>* next;
};

template <class T>
class linkedList {
private:
    Node<T>* head;

public:
    linkedList();
    
    void insertAtBeginning(T value);
    void insertAtEnd(T value);
    void insertAtPosition(T value, int position);
    
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(int position);
};

#include "linkedlist.cpp"
#endif
