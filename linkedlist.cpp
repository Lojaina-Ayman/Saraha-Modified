#pragma once
#include "linkedList.h"
#include <iostream>

// Constructor
template <class T>
linkedList<T>::linkedList() : head(nullptr) {}

// Insert at beginning
template <class T>
void linkedList<T>::insertAtBeginning(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end
template <class T>
void linkedList<T>::insertAtEnd(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node<T>* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at specific position
template <class T>
void linkedList<T>::insertAtPosition(T value, int position) {
    assert(position >= 1);
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = head;
    for (int i = 1; i < position - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (!temp) {
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
template <class T>
void linkedList<T>::deleteFromBeginning() {
    if (!head)
        return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
template <class T>
void linkedList<T>::deleteFromEnd() {
    if (!head)
        return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Delete from specific position
template <class T>
void linkedList<T>::deleteFromPosition(int position) {
    assert(position >= 1);
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    Node<T>* temp = head;
    for (int i = 1; i < position - 1 && temp; ++i) {
        temp = temp->next;
    }
    if (!temp || !temp->next) {
        std::cout << "Position out of range." << std::endl;
        return;
    }
    Node<T>* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Get size of the list
template <class T>
int linkedList<T>::size() const {
    int count = 0;
    Node<T>* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Access value at index
template <class T>
T linkedList<T>::getAt(int index) const {
    Node<T>* temp = head;
    for (int i = 0; i < index && temp; ++i) {
        temp = temp->next;
    }
    assert(temp != nullptr); // Out of bounds
    return temp->data;
}
