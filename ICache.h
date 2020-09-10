#ifndef LRUPROJECT_ICACHE_H
#define LRUPROJECT_ICACHE_H

/**
 * Interface Class Cache Definition
 */
template <class T1, class T2>
class ICache{
public:
    virtual T1 getMostRecentKey() = 0;
    virtual T2 getValueFromKey(T1 key) = 0;
    virtual void insertKeyValuePair(T1 key, T2 value) = 0;
    virtual ~ICache() = default;
};

#endif //LRUPROJECT_ICACHE_H
