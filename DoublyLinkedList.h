
#ifndef LRUPROJECT_DOUBLYLINKEDLIST_H
#define LRUPROJECT_DOUBLYLINKEDLIST_H

#include <iostream>

class Node {
public:
    char key;
    int value;
    Node* prev;
    Node* next;
    // Default Constructor
    Node() {
        prev = nullptr;
        next = nullptr;
        key = 'a';
        value = -1;
    }
    // Custom Constructor
    Node(char key, int value){
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }

    void killMe(){
        std::cout << "** killMe **\n";
        if(this->next){
            this->next->killMe();
        }
        std::cout << "Delete this Node: (" << key << ": " << value << ") \n";
        delete this;
    }
};

class DoublyLinkedList {
public:
    Node* head;     // most recently used
    Node* tail;     // least recently used
    DoublyLinkedList();
    void push_front(Node* node);
    void print();
    void printReverse();
};

#endif //LRUPROJECT_DOUBLYLINKEDLIST_H
