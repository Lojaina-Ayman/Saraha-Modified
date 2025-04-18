#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cassert>

template <class T>
struct Node {
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}  // Constructor added to avoid "deleted function" error
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

    int size() const;
    T getAt(int index) const;
};

#include "linkedList.cpp" // Include the implementation at the end

#endif // LINKEDLIST_H
