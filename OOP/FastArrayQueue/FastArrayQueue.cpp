#include "FastArrayQueue.h"
#include <iostream>
#include <string.h>

using namespace std;

FastArrayQueue::FastArrayQueue(int maxSize)
{
    this->maxSize = maxSize;
    curSize = 0;
    in = 0;
    out = 0;
    L = new int[this->maxSize];
}

FastArrayQueue::~FastArrayQueue()
{
    delete[] L;
}

void FastArrayQueue::enQueue(int e)
{
    // * validate (queue Full)
    if (curSize >= maxSize)
    {
        cerr << "Error : Queue is full..." << endl;
        return;
    }

    // * enqueue alg.(example)
    L[in] = e;
    in = (in + 1) % maxSize;

    curSize++;
}

int FastArrayQueue::deQueue()
{
    // * validate (queue empty)
    if (curSize <= 0)
    {
        cerr << "Error : Queue is Empty..." << endl;
        return -1;
    }

    // * dequeue alg.(example)
    int t = L[out];
    out = (out + 1) % maxSize;
    curSize--;

    return t;
}

int FastArrayQueue::front()
{
    // * validate (queue empty)
    if (curSize <= 0)
    {
        cerr << "Error : Queue is Empty..." << endl;
        return -1;
    }

    // * get front (example)

    return L[out];
}

int FastArrayQueue::rear()
{
    // * validate (queue empty)
    if (curSize <= 0)
    {
        cerr << "Error : Queue is Empty..." << endl;
        return -1;
    }

    // * get front (example)

    return L[((in - 1) + maxSize) % maxSize];
}

void FastArrayQueue::display()
{
    // * Queue. {e0, e1, en...,} curSize/maxSize
    cout << "Q : {";
    if (curSize == 0)
    {
        cout << "}";
    }
    else
    {
        for (int i = 0; i < curSize; i++)
        {
            cout << L[(out + i) % maxSize];
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
         << "Size : " << curSize << "/" << maxSize << ", in : " << in << ", out : " << out << endl;
}

void FastArrayQueue::enQueueFloat(float e)
{
    // * float (32 bits) => int Queue(32 bits)
    int *pFloat = (int *)&e;
    enQueue(*pFloat);
}

float FastArrayQueue::deQueueFloat()
{
    int data = deQueue();
    float *pFloat = (float *)&data;
    return *pFloat;
}

void FastArrayQueue::enQueueLong(long e)
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

long FastArrayQueue::deQueueLong()
{
    unsigned long mData = (unsigned long)deQueue();
    unsigned long lData = (unsigned long)deQueue();

    unsigned long data = (mData << 32) & 0xFFFFFFFF00000000 |
                         (lData << 0) & 0x00000000FFFFFFFF;
    return (long)data;
}

void FastArrayQueue::enQueueCString(char *s)
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

char *FastArrayQueue::deQueueCString()
{
    unsigned long mData = (unsigned long)deQueue();
    unsigned long lData = (unsigned long)deQueue();

    unsigned long addr = (mData << 32) & 0xFFFFFFFF00000000 |
                         (lData << 0) & 0x00000000FFFFFFFF;
    return (char *)addr; // !!! don't forget to free memory, by Users
}
