#if !defined(_HASHTABLE_H)
#define _HASHTABLE_H

#include "../ArrayList/arrayList.h"

#define INIT_TABLE_SIZE 4
#define REHASH_THRESHOLD 80.0
#define REHASH_EXPAND 2.0

class HashTable
{
private:
    ArrayList *Table;
    int curSize; 
    int maxSize;
public:
    HashTable(int maxSize = INIT_TABLE_SIZE);
    ~HashTable();
    void display();
    
    void addkey(int key);
    int searchkey(int key); // * return index (position)

private: // private method
    int probingFunction(int i);
    int hashFunction(int key, int n, int i);
    void rehash();
    
};

#endif // _HASHTABLE_H
