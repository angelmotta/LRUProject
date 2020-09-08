#include "DoublyLinkedList.h"
#include <iostream>


DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::push_front(Node *node) {
    if(head){
        Node* cpHead = head;
        head->prev = node;
        head = node;
        node->next = cpHead;
    }
    else {  // if does not exist head
        head = node;
        tail = node;
    }
}

void DoublyLinkedList::print() {
    std::cout << "** Printing Doubly Linked List **\n";
    Node* temp = head;
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

void DoublyLinkedList::printReverse() {
    std::cout << "** Printing in 'Reverse' the Doubly Linked List **\n";
    Node* temp = tail;
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
