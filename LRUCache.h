#ifndef LRUPROJECT_LRUCACHE_H
#define LRUPROJECT_LRUCACHE_H
#include "DoublyLinkedList.h"
#include <unordered_map>

template <class T1, class T2>
class LRUCache {
private:
    int currentSize;
    int maxSize;
    std::unordered_map<T1, Node<T1, T2>*> mapCache;
    DoublyLinkedList<T1, T2>* dll;
public:
    LRUCache(int capacity);
    ~LRUCache();
    T1 getMostRecentKey();
    void updatePositionNode(Node<T1, T2>* node);
    T2 getValueFromKey(T1 key);
    void insertKeyValuePair(T1 key, T2 value);
    void print();
    void explainAnalyze();
};

/**
 * Implementation Methods
 */
template<class T1, class T2>
LRUCache<T1, T2>::LRUCache(int capacity) {
    currentSize = 0;
    maxSize = capacity;
    dll = new DoublyLinkedList<T1, T2>();
}

template<class T1, class T2>
LRUCache<T1, T2>::~LRUCache() {
    std::cout << "** Calling Destructor for LRUCache **\n";
    if(dll->head){
        dll->head->killMe();
    }
}

template<class T1, class T2>
T1 LRUCache<T1, T2>::getMostRecentKey() {
    std::cout << "** getMostRecentKey: ** \n";
    return dll->head->key;
}

template<class T1, class T2>
void LRUCache<T1, T2>::updatePositionNode(Node<T1, T2> *node) {
    Node<T1, T2>* ptrPrevNode = node->prev;
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

template<class T1, class T2>
T2 LRUCache<T1, T2>::getValueFromKey(T1 key) {
    std::cout << "** getValueFromKey '" << key <<"' **\n";
    if(mapCache.find(key) != mapCache.end()){    // if we have the element requested
        int valResult = mapCache[key]->value;
        // Update Cache structure if node is distinct to head
        Node<T1, T2>* node = mapCache[key];
        if(node != dll->head){
            //std::cout << "(Update Cache Structure)\n";
            updatePositionNode(node);
        }
        return valResult;
    }
    return -1;
}

template<class T1, class T2>
void LRUCache<T1, T2>::insertKeyValuePair(T1 key, T2 value) {
    std::cout << "** insertKeyValuePair: (" << key << ":" << value << ") ** \n";
    if(mapCache.find(key) != mapCache.end()){   // Update existing key
        std::cout << "Existing Key found...Updating value and position\n";
        Node<T1, T2>* node = mapCache[key];
        node->value = value;
        // Update position
        if(node != dll->head){
            updatePositionNode(node);
        }
    }
    else{ // Add new node
        std::cout << "New Key, Inserting node (" << key << ":" << value << ")\n";
        Node<T1, T2>* node = new Node(key, value);
        if(currentSize == maxSize){
            std::cout << "Full Capacity...Deleting the least recently used\n";
            // Delete tail node to have space and Update Map
            // Delete tail entry from map
            auto itKey = mapCache.find(dll->tail->key);
            mapCache.erase(itKey);
            // delete least used and free the memory
            Node<T1, T2>* ptrTailPrev = dll->tail->prev;
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

template<class T1, class T2>
void LRUCache<T1, T2>::print() {
    std::cout << "** View Map structure **\n";
    for(auto element : mapCache){
        std::cout << element.first << ": " << element.second->value << ", ";
    }
    std::cout << "\n";
}

template<class T1, class T2>
void LRUCache<T1, T2>::explainAnalyze() {
    std::cout << "** Check internal Structure **\n";
    //print();
    dll->print();
    //dll->printReverse();
    std::cout << "** ------------------------- **\n";
}

#endif //LRUPROJECT_LRUCACHE_H
