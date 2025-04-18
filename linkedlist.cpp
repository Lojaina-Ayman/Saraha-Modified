
#include "linkedlist.h"
#include <iostream>

template <class T>
linkedList<T>::linkedList() : head(nullptr) {}

template <class T>
void linkedList<T>::insertAtBeginning(T value) {
    Node<T>* newNode = new Node<T>();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

template <class T>
void linkedList<T>::insertAtEnd(T value) {
    Node<T>* newNode = new Node<T>();
    newNode->data = value;
    newNode->next = nullptr;
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

template <class T>
void linkedList<T>::insertAtPosition(T value, int position) {
    assert(position >= 1);
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    Node<T>* newNode = new Node<T>();
    newNode->data = value;

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

template <class T>
void linkedList<T>::deleteFromBeginning() {
    if (!head)
        return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

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

template class linkedList<int>;
template class linkedList<double>;