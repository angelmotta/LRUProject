#ifndef LRUPROJECT_DOUBLYLINKEDLIST_H
#define LRUPROJECT_DOUBLYLINKEDLIST_H

#include "Node.h"

/**
 * Doubly Linked List - Definition
 * Self Organized List
 */

template<class T1, class T2>
class DoublyLinkedList {
public:
    Node<T1, T2>* head;     // most recently used
    Node<T1, T2>* tail;     // least recently used
    DoublyLinkedList();
    void push_front(Node<T1, T2>* node);
    void print();
    void printReverse();
};

/**
 * Implementation Methods
 */
template<class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

template<class T1, class T2>
void DoublyLinkedList<T1, T2>::push_front(Node<T1, T2> *node) {
    if(head){
        Node<T1, T2>* cpHead = head;
        head->prev = node;
        head = node;
        node->next = cpHead;
    }
    else {  // if does not exist head
        head = node;
        tail = node;
    }
}

template<class T1, class T2>
void DoublyLinkedList<T1, T2>::print() {
    std::cout << "** Printing Doubly Linked List **\n";
    Node<T1, T2>* temp = head;
    while(temp){
        if(temp->next){
            std::cout << "( " << temp->key << ": " << temp->value << " ) <--> ";
        }
        else{
            std::cout << "( " << temp->key << ": " << temp->value << " ) --> ";
        }
        temp = temp->next;
    }
    std::cout << "\n";
}

template<class T1, class T2>
void DoublyLinkedList<T1, T2>::printReverse() {
    std::cout << "** Printing in 'Reverse' the Doubly Linked List **\n";
    Node<T1, T2>* temp = tail;
    std::cout << "Tail...";
    while(temp){
        if(temp->prev){
            std::cout << "( " << temp->key << ": " << temp->value << " ) <--> ";
        }
        else{
            std::cout << "( " << temp->key << ": " << temp->value << " ) ";
        }
        temp = temp->prev;
    }
    std::cout << "...Head\n";
}


#endif //LRUPROJECT_DOUBLYLINKEDLIST_H
