#include "FastLinkedQueue.h"
#include <iostream>
#include <string.h>

using namespace std;

FastLinkedQueue::FastLinkedQueue()
{
    firstNode = new ChainNode;
    LastNode = firstNode;
    curSize = 0;
}

FastLinkedQueue::~FastLinkedQueue()
{
    ChainNode *p = firstNode;
    while (p != NULL)
    {
        ChainNode *n = p->next;
        delete p;
        p = n;
    }
}

void FastLinkedQueue::enQueue(int e)
{
    // * validate (queue Full)
    if (isFull())
    {
        cerr << "Error : Queue is full..." << endl;
        return;
    }

    // * enqueue alg.(example)
    LastNode->next = new ChainNode(e, LastNode->next);

    LastNode = LastNode->next;
    curSize++;
}

int FastLinkedQueue::deQueue()
{
    // * validate (queue empty)
    if (isEmpty())
    {
        cerr << "Error : Queue is Empty..." << endl;
        return -1;
    }

    ChainNode *p = firstNode;
    // * q = delete
    ChainNode *q = p->next;
    // * node r -> after delete node
    ChainNode *r = q->next;

    int temp = q->element;

    delete q;
    p->next = r;

    curSize--;

    // * before deQueue function -> checking and Setup new ChainNode
    if (curSize == 0)
    {
        firstNode = new ChainNode;
        LastNode = firstNode;
    }

    return temp;
}

int FastLinkedQueue::front()
{
    if (isEmpty())
    {
        cerr << "Error : Queue is Empty..." << endl;
        return -1;
    }
    return firstNode->next->element;
}

int FastLinkedQueue::rear()
{
    if (isEmpty())
    {
        cerr << "Error : Queue is Empty..." << endl;
        return -1;
    }
    return LastNode->element;
}

void FastLinkedQueue::display()
{
    // * Queue. {e0, e1, en...,} curSize/maxSize
    cout << "Q : {";
    if (curSize == 0)
    {
        cout << "}";
    }
    else
    {
        ChainNode *p = firstNode->next;
        for (int i = 0; i < curSize; i++, p = p->next)
        {
            cout << p->element;
            if (i < curSize - 1)
            {
                cout << ", ";
            }
            else
            {
                cout << "}";
            }
        }
    }
    cout << ", "
         << "Size : " << curSize << endl;
}

bool FastLinkedQueue::isFull()
{
    // * try to create new node
    ChainNode *p = new ChainNode;
    if (p != NULL)
        return false;
    else
        return true;

    delete p;
}

bool FastLinkedQueue::isEmpty()
{
    return curSize <= 0;
}

void FastLinkedQueue::enQueueFloat(float e)
{
    // * float (32 bits) => int Queue(32 bits)
    int *pFloat = (int *)&e;
    enQueue(*pFloat);
}

float FastLinkedQueue::deQueueFloat()
{
    int data = deQueue();
    float *pFloat = (float *)&data;
    return *pFloat;
}

void FastLinkedQueue::enQueueLong(long e)
{
    // * long (64 bits) => int (32 bits) | int (32 bits)
    // *                        mData        lData
    // *            most significant data  least significant data

    unsigned long data = (unsigned long)e;
    unsigned int mData = (data >> 32) & 0x00000000FFFFFFFF;
    unsigned int lData = (data >> 0) & 0x00000000FFFFFFFF;

    enQueue(mData);
    enQueue(lData);
}

long FastLinkedQueue::deQueueLong()
{
    unsigned long mData = (unsigned long)deQueue();
    unsigned long lData = (unsigned long)deQueue();

    unsigned long data = (mData << 32) & 0xFFFFFFFF00000000 |
                         (lData << 0) & 0x00000000FFFFFFFF;
    return (long)data;
}

void FastLinkedQueue::enQueueCString(char *s)
{
    char *p = (char *)malloc((strlen(s) + 1) * sizeof(char));
    strcpy(p, s);
    // * char * (64 bits) => int (32 bits) | int (32 bits)
    // *                        mData        lData
    // *            most significant data  least significant data

    unsigned long addr = (unsigned long)p;
    unsigned int mData = (addr >> 32) & 0x00000000FFFFFFFF;
    unsigned int lData = (addr >> 0) & 0x00000000FFFFFFFF;

    enQueue(mData);
    enQueue(lData);
}

char *FastLinkedQueue::deQueueCString()
{
    unsigned long mData = (unsigned long)deQueue();
    unsigned long lData = (unsigned long)deQueue();

    unsigned long addr = (mData << 32) & 0xFFFFFFFF00000000 |
                         (lData << 0) & 0x00000000FFFFFFFF;
    return (char *)addr; // !!! don't forget to free memory, by Users
}