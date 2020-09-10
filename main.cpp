#include <iostream>
#include "LRUCache.h"

using namespace std;

int main() {
    LRUCache<char, int> lruCacheObj(3);
    lruCacheObj.insertKeyValuePair('b', 2);
    lruCacheObj.insertKeyValuePair('a', 1);
    lruCacheObj.insertKeyValuePair('c', 3);
    lruCacheObj.explainAnalyze();
    std::cout << lruCacheObj.getMostRecentKey() << "\n";    // 'c'
    std::cout << lruCacheObj.getValueFromKey('a') << "\n";   // Return value (Update case 1)
    std::cout << lruCacheObj.getMostRecentKey() << "\n";    // 'a'
    lruCacheObj.insertKeyValuePair('d', 4);     // cache maxSize reached; delete lru and update
    std::cout << lruCacheObj.getValueFromKey('b') << "\n";   //  return -1, 'b' was evicted in the previous operation
    lruCacheObj.explainAnalyze();
    lruCacheObj.insertKeyValuePair('a', 5); // 'a' already exist; update value and position
    lruCacheObj.explainAnalyze();
    std::cout << lruCacheObj.getValueFromKey('a') << "\n";  // 5
    lruCacheObj.explainAnalyze();
//     Test 2
//    LRUCache lruCacheObj(2);
//    lruCacheObj.insertKeyValuePair('2', 1);
//    lruCacheObj.insertKeyValuePair('2', 2);
//    std::cout << lruCacheObj.getValueFromKey('2') << "\n";
//    lruCacheObj.insertKeyValuePair('1', 1);
//    lruCacheObj.insertKeyValuePair('4', 1);
//    std::cout << lruCacheObj.getValueFromKey('2') << "\n";
//    lruCacheObj.explainAnalyze();
    // Test Template
//    LRUCache<char, char> lruCacheObj2(3);
//    lruCacheObj2.insertKeyValuePair('b', '2');
//    lruCacheObj2.insertKeyValuePair('a', '1');
//    lruCacheObj2.insertKeyValuePair('c', '3');
//    lruCacheObj2.explainAnalyze();
    return 0;
}
