#if !defined(_FASTLINKEDQUEUE_H)
#define _FASTLINKEDQUEUE_H

#include "../ChainNode/ChainNode.h"

class FastLinkedQueue
{
    private:
        ChainNode *firstNode;
        ChainNode *LastNode;
        int curSize;

        
    public:
        FastLinkedQueue(); // * constructor
        ~FastLinkedQueue();

        // * method
        void enQueue(int e);
        int deQueue();
        int front();
        int rear();

        void display();

        bool isFull();
        bool isEmpty();

        void append(int e){ enQueue(e); };
        int remove(){ return deQueue(); };
        int head(){ return front(); };
        int back(){ return rear(); };
};

#endif // _FASTLINKEDQUEUE_H
