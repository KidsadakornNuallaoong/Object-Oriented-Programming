#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int maxSize)
{
    // * store maxsize
    this->maxSize = maxSize;
    // * create table
    Table = new ArrayList(this->maxSize);
    // * fill -1 all element
    for (int i = 0; i < this->maxSize; i++)
    {
        Table->add(i, -1); // * -1 empty slot
    }

    curSize = 0;
}

HashTable::~HashTable()
{
    // * delete table
    delete Table;
}

void HashTable::display()
{
    // * 0: 4
    // * 1: 12
    // * 2: 8
    // * 3: -
    // * 3/4(75.00%)
    for (int i = 0; i < maxSize; ++i)
    {
        printf("%3d: ", i);
        if(Table->get(i) < 0) // * -1: Empty slot
            printf("%3s\n", "-");
        else // * any Value (not empty) 
            printf("%3d\n", Table->get(i));
    }
    // * cal percen curSize & maxSize
    printf("%d/%d(%0.2f%%)\n", curSize, maxSize, ((double)curSize / (double)maxSize * 100));
    
}

void HashTable::addkey(int key)
{
      for(int i = 0; i < maxSize; ++i){
        int index = hashFunction(key, maxSize, i);
        // ? check slot i empty
        if(Table->get(index) < 0){
            // * no collision
            Table->set(index, key);
            curSize++;
            break;
        } 
        // * not empty --> loopNext

        cout << "Collision at index : " << index << endl;
      }
    // * cheack rehash
    double percent = (double)curSize / (double)maxSize * 100;
    if(percent >= REHASH_THRESHOLD){
        rehash();
    }
}

int HashTable::searchkey(int key)
{
    // * get key to hash
    // * find index key
    for(int i = 0; i < maxSize; ++i){
        int index = hashFunction(key, maxSize, i);

        if(Table->get(index) == key){
            // * no collision
            cout << "Found " << key << " at index " << index<< endl;
            curSize++;
            break;
        } 
        // * if not found & reSearch
        cout << "Not Found " << key << " at index " << index << endl;
        if(i == maxSize-1){
            cout << "Found " << key << " at index -1" << endl;
        }
    }

    return 0;
}

int HashTable::probingFunction(int i)
{
    return i; // * linear probing
    // * return i * i // f(i) = i^2 + , quadratic 
}

int HashTable::hashFunction(int key, int n, int i)
{
    return (key % n + probingFunction(i)) % n;
}

void HashTable::rehash()
{
    int oldSize = maxSize;
    int newSize = REHASH_EXPAND * (double)maxSize;

    ArrayList *newTable = new ArrayList(newSize); // * Create new table
    maxSize = newSize;
    for(int i = 0; i < newSize; i++){
        newTable->add(i,-1);
    }
    curSize = 0;

    // * tranfer Data from Table to new Table
    for(int i = 0; i < oldSize; ++i){
        if(Table->get(i) >= 0){ // * any value
            int key = Table->get(i);
            
            for(int j = 0;j < maxSize; ++j){
                // * count and add to newTable
                int index = hashFunction(key, maxSize, j); 
                if(newTable->get(index) < 0){
                    newTable->set(index, key);
                    curSize++;
                    break;
                }
                // * not empty
                cout << "Collision at index: " << index << endl;
            }
        }
    }

    // * delete Old Table 
    delete Table;

    // * set Table point to new Table
    Table = newTable;
}