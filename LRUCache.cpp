#include "LRUCache.h"
#include <iostream>

LRUCache::LRUCache(int capacity) {
    currentSize = 0;
    maxSize = capacity;
    dll = new DoublyLinkedList();
}

LRUCache::~LRUCache() {
    std::cout << "** Destructor LRUCache **\n";
    dll->head->killMe();
}

char LRUCache::getMostRecentKey() {
    std::cout << "** getMostRecentKey: ** \n";
    return dll->head->key;
}

void LRUCache::updatePositionNode(Node *node) {
    Node* ptrPrevNode = node->prev;
    if(node == dll->tail){
        ptrPrevNode->next = nullptr;
        dll->tail = ptrPrevNode;
    }
    else { // adelante hay nodo
        ptrPrevNode->next = node->next;
        node->next->prev = ptrPrevNode;
    }
    // Update head
    node->next = dll->head;
    node->prev = nullptr;
    dll->head->prev = node;
    dll->head = node;
}

int LRUCache::getValueFromKey(char key) {
    std::cout << "** getValueFromKey '" << key <<"' **\n";
    if(mapCache.find(key) != mapCache.end()){    // if we have the element requested
        int valResult = mapCache[key]->value;
        // Update Cache structure if node is distinct to head
        Node* node = mapCache[key];
        if(node != dll->head){
            std::cout << "(Update Cache Structure)\n";
            updatePositionNode(node);
        }
        return valResult;
    }
    return -1;
}

void LRUCache::insertKeyValuePair(char key, int value) {
    std::cout << "** insertKeyValuePair: (" << key << ":" << value << ") ** \n";
    if(mapCache.find(key) != mapCache.end()){   // Update existing key
        std::cout << "This is an existing Key...Updating value and position\n";
        Node* node = mapCache[key];
        node->value = value;
        // Update position
        if(node != dll->head){
            updatePositionNode(node);
        }
    }
    else{ // Add new node
        std::cout << "New Key, Inserting node (" << key << ":" << value << ")\n";
        Node* node = new Node(key, value);
        if(currentSize == maxSize){
            std::cout << "Full Capacity: First, We need delete the least recently used\n";
            // Delete tail node to have space and Update Map
            // Delete tail entry from map
            auto itKey = mapCache.find(dll->tail->key);
            mapCache.erase(itKey);
            // delete least used and free the memory
            Node* ptrTailPrev = dll->tail->prev;
            delete dll->tail;
            dll->tail = ptrTailPrev;
            if(dll->tail){
                dll->tail->next = nullptr;
            }
            else {
                dll->head = nullptr;
            }
            currentSize--;
        }
        //std::cout << "Adding new key-value inside node " << key << ":" << value << "\n";
        dll->push_front(node);
        mapCache[key] = node;
        currentSize++;
    }
}

void LRUCache::print() {
    std::cout << "** View Map structure **\n";
    for(auto element : mapCache){
        std::cout << element.first << ": " << element.second->value << ", ";
    }
    std::cout << "\n";
}

void LRUCache::explainAnalyze() {
    std::cout << "** Check internal Structure **\n";
    //print();
    dll->print();
    //dll->printReverse();
    std::cout << "** ------------------------- **\n";
}

