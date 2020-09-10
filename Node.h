#ifndef LRUPROJECT_NODE_H
#define LRUPROJECT_NODE_H

#include <iostream>

/**
 * Class Node Definition
 */
template<class T1, class T2>
class Node {
public:
    T1 key;
    T2 value;
    Node<T1, T2>* prev;
    Node<T1, T2>* next;
    Node();
    Node(T1 key, T2 value);
    void killMe();
};

/**
 * Implementation Member Methods
 */
// Default Constructor
template<class T1, class T2>
Node<T1, T2>::Node(){
    prev = nullptr;
    next = nullptr;
    key = 'a';
    value = -1;
}
// Custom Constructor
template<class T1, class T2>
Node<T1, T2>::Node(T1 key, T2 value){
    this->key = key;
    this->value = value;
    prev = nullptr;
    next = nullptr;
}

// Called by Double Linked List's Destructor
template<class T1, class T2>
void Node<T1, T2>::killMe(){
    //std::cout << "** killMe **\n";
    if(this->next){
        this->next->killMe();
    }
    delete this;
}

#endif //LRUPROJECT_NODE_H
