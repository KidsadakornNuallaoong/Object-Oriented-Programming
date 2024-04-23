#include "FastArrayQueue.h"
#include <iostream>

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
    delete []L;
}

void FastArrayQueue::enQueue(int e)
{
    // * validate (queue Full)
    if(curSize >= maxSize){
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
    if(curSize <= 0){
        cerr << "Error : Queue is Empty..." << endl;
        return -1;
    }

    // * dequeue alg.(example)
    int t = L[out];
    L[out] = 0;
    out = (out+1) % maxSize;
    curSize--;

    return t;
}

int FastArrayQueue::front()
{
    // * validate (queue empty)
    if(curSize <= 0){
        cerr << "Error : Queue is Empty..." << endl;
        return -1;
    } 

    // * get front (example)

    return L[out];
}

int FastArrayQueue::rear()
{
    // * validate (queue empty)
    if(curSize <= 0){
        cerr << "Error : Queue is Empty..." << endl;
        return -1;
    }

    // * get front (example)

    return L[((in-1) + maxSize) % maxSize];
}

void FastArrayQueue::display()
{
    // * Queue. {e0, e1, en...,} curSize/maxSize
    cout << "Q : {";
    if(curSize == 0){
        cout << "}";
    } else {
        for(int i = 0; i < curSize; i++){
            cout << L[(out + i) % maxSize];
            if(i < curSize-1){
                cout << ", ";
            } else {
                cout << "}";
            }
        }
    }
    cout << ", " << "Size : " << curSize << "/" << maxSize << ", in : " << in << ", out : " << out  << endl;
}