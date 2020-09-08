#ifndef LRUPROJECT_LRUCACHE_H
#define LRUPROJECT_LRUCACHE_H

#include "DoublyLinkedList.h"
#include <unordered_map>

class LRUCache {
private:
    int currentSize;
    int maxSize;
    std::unordered_map<char, Node*> mapCache;
    DoublyLinkedList* dll;
public:
    LRUCache(int capacity);
    ~LRUCache();
    char getMostRecentKey();
    void updatePositionNode(Node* node);
    int getValueFromKey(char key);
    void insertKeyValuePair(char key, int value);
    void print();
    void explainAnalyze();
};


#endif //LRUPROJECT_LRUCACHE_H
