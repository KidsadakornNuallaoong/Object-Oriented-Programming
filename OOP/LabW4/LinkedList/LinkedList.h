#if !defined(_LINKEDLSIT_H)
#define _LINKEDLSIT_H
#include "../ChainNode/ChainNode.h"

class LinkedList
{
private: // * data
    ChainNode *firstNode;
    int curSize;

protected:
    bool isFull();
    bool isEmpty();

public:            // * method
    LinkedList();  // ! contructor *important (1)*
    ~LinkedList(); // ! destructor

    // * basic method
    int size();
    int indexOf(int e);
    int get(int i);
    void set(int i, int e);
    int remove(int i);
    void add(int i, int e);

    void clear();
    int max();
    int min();

    int oddCount();
    int evenCount();
    float sum();
    float mean();
    void sort();

    void appendRandom(int round);

    void swap(ChainNode *p, ChainNode *q);

    // * addition method
    void display();
};

#endif // _LINKEDLSIT_H