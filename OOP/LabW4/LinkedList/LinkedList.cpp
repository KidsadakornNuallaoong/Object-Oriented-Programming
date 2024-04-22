#include <iostream>
#include "LinkedList.h"

using namespace std;

bool LinkedList::isFull()
{
    // * try to create new node
    ChainNode *p = new ChainNode;
    bool returnBool; // *  can create new node
    if (p != NULL)
        returnBool = false;
    else
        returnBool = true;

    delete p;

    return returnBool;
}

bool LinkedList::isEmpty()
{
    // * if curSize = 0 is true
    // * if curSize != 0 is fale
    return curSize == 0;
}

LinkedList::LinkedList()
{
    // * set curSize = 0
    curSize = 0;

    firstNode = new ChainNode(0, NULL);
}

LinkedList::~LinkedList()
{
    // * set p to dummy
    ChainNode *p = firstNode;

    // * iterative node
    while (p != NULL)
    {
        ChainNode *n = p->next;

        delete p;
        p = n;
    }
}

int LinkedList::size()
{
    // * get Size to User
    return curSize;
}

int LinkedList::indexOf(int e)
{
    if (isEmpty())
    {
        cerr << "[Massage Error] : memory is empty!!!" << endl;
        return -1;
    }

    int i = 0;
    ChainNode *p = firstNode->next;

    // * loop find index of element
    while (p->element != e && i < curSize - 1)
    {
        p = p->next; // * p get move address

        i++;
    }
    if (p->element != e)
    {
        cerr << "[Massage Error] : not found" << endl;
        return -1;
    }

    return i;
}

int LinkedList::get(int i)
{
    // * check empty and full
    if (isEmpty())
    {
        cerr << "[Massage Error] : Empty Stack!!!" << endl;
        return -1;
    }

    // * check lower
    if (i < 0)
    {
        cerr << "[Massage Warning] : i is lower bound" << endl;
        return -1;
    }
    // * check upper
    else if (i >= curSize)
    {
        cerr << "[Massage Warning] : i is over bound" << endl;
        return -1;
    }

    int j = 0;
    // * get element from index
    ChainNode *p = firstNode->next;
    // * how i get element from index??
    while (j != i && j <= curSize - 1)
    {
        p = p->next;
        j++;
    }

    return p->element;
}

void LinkedList::set(int i, int e)
{
    // * check empty
    if (isEmpty())
    {
        cerr << "[Massage Error] : Empty Stack!!!" << endl;
        return;
    }

    // * check lower
    if (i < 0)
    {
        cout << "[Massage Warning] : i is lower bound" << endl;
        return;
    }
    // * check upper
    else if (i >= curSize)
    {
        cout << "[Massage Warning] : i is over bound" << endl;
        return;
    }

    // * loop to index [i] <--
    // * set element to index something
    int j = 0;
    ChainNode *p = firstNode->next;

    while (j != i && j <= curSize - 1)
    {
        p = p->next;
        j++;
    }
    p->element = e;
}

int LinkedList::remove(int i)
{
    // * check empty and full
    if (isEmpty())
    {
        cerr << "[Massage Error] : Empty Stack!!!" << endl;
        return -1;
    }

    // * check lower
    if (i < 0)
    {
        cout << "[Massage Warning] : i is lower bound" << endl;
        return -1;
    }
    // * check upper
    else if (i >= curSize)
    {
        cout << "[Massage Warning] : i is over bound" << endl;
        return -1;
    }

    int j = 0;
    // * node p -> before node to delete
    ChainNode *p = firstNode;

    while (j < i)
    {
        p = p->next;
        j++;
    }

    // * q = delete
    ChainNode *q = p->next;
    // * node r -> after delete node
    ChainNode *r = q->next;

    int temp = q->element;

    delete q;
    p->next = r;

    curSize--;

    return temp;
}

void LinkedList::add(int i, int e)
{
    // * check full
    if (isFull())
    {
        cerr << "[Massage Error] : memory is full!!!" << endl;
        return;
    }

    // * check lower bound
    if (i < 0)
    {
        cout << "[Massage Warning] : Lower bound" << endl;
        cout << "[Massage] : Index is changed to 0" << endl;
        i = 0;
    }
    // * check upper bound
    else if (i > curSize)
    {
        cout << "[Massage Warning] : upper bound" << endl;
        cout << "[Massage] : Index is changed to " << curSize << endl;
        i = curSize;
    }

    // * p point to dummy
    ChainNode *p = firstNode;

    // * move p to forward for i times
    for (int j = 0; j < i; j++)
        p = p->next;

    // * q point to new node
    ChainNode *q = new ChainNode(e, p->next);

    // * adjust link
    p->next = q;

    // * increment cursize
    curSize++;
}

void LinkedList::clear()
{
    // * u can't set curSize = 0
    // * set p to dummy
    ChainNode *p = firstNode->next;

    // * iterative node
    while (p != NULL)
    {
        ChainNode *n = p->next;

        delete p;
        p = n;
    }

    // * set next of dummy point to NULL
    firstNode->next = NULL;

    // * set current size to zero
    curSize = 0;
}

int LinkedList::max()
{
    // * check empty and full
    if (isEmpty())
    {
        cerr << "[Massage Error] Empty Stack!!!" << endl;
        return -1;
    }

    // * move node --> next and get high value
    // * loop .next
    ChainNode *p = firstNode->next;

    int i = 0;
    int n = p->element;

    while (i <= curSize - 1, p = p->next)
    {
        if (n < p->element)
        {
            // * get value 1 > value 2
            n = p->element;
        }
        // * move node --> p.next
        i++;
    }

    return n;
}

int LinkedList::min()
{
    // * check empty list
    if (isEmpty())
    {
        cerr << "[Massage Error] : memory is empty!!!" << endl;
        return -1;
    }

    // * move node --> next and get low value
    // * loop .next
    ChainNode *p = firstNode->next;

    int i = 0;
    int n = p->element;

    while (i <= curSize - 1, p = p->next)
    {
        if (n > p->element)
        {
            // * get value 1 < value 2
            n = p->element;
        }
        // * move node --> p.next
        i++;
    }

    return n;
}

int LinkedList::oddCount()
{
    // * check empty list
    if (isEmpty())
    {
        cerr << "[Massage Error] : memory is empty!!!" << endl;
        return -1;
    }

    int i = 0;
    int count = 0;

    ChainNode *p = firstNode;

    while (p != NULL, p = p->next)
    {
        // * checking value divide 2 is false
        // * count += p->element % 2;
        if (p->element % 2)
            count++;

        // * if(p->element % 2 == true){
        // *    cout << p->element << ",";
        // *    Odd number counting
        // * count = p->element;

        // * count += p->element % 2;
        // * cout << count << ",";

        // * Odd number counting
    }

    return count;
}

int LinkedList::evenCount()
{
    if (isEmpty())
    {
        cerr << "[Massage Error] : memory is empty!!!" << endl;
        return -1;
    }

    int cur = curSize;

    return cur -= oddCount();
}

float LinkedList::sum()
{
    if (isEmpty())
    {
        cerr << "[Massage Error] : memory is empty!!!" << endl;
        return -1;
    }

    int i = 0, sum = 0;

    ChainNode *p = firstNode;

    while (i < curSize - 1, p = p->next)
    {
        // * + value for find sum
        sum += p->element;
        ++i;
    }

    return sum;
}

float LinkedList::mean()
{
    if (isEmpty())
    {
        cerr << "[Massage Error] : memory is empty!!!" << endl;
        return -1;
    }
    float mean = 0;

    // * set node p to first node
    ChainNode *p = firstNode->next;
    // * find value by summation divide curSize
    // * another way we can find value by round num
    mean = sum() / curSize;

    return mean;
}

void LinkedList::sort()
{
    if (isEmpty())
    {
        cerr << "[Massage Error] Empty Stack!!!" << endl;
        return;
    }

    // * sort minimum value to max value
    // * loop  checking element
    // * swap element
    int i = 0;

    // * loop from curSize
    while (i < curSize - 1)
    {
        int j = 0;
        ChainNode *p = firstNode->next;
        // * loop for swap element
        while (j < curSize - 1)
        {
            if (p->element > p->next->element)
            {
                // * swap element
                swap(p, p->next);
            }
            p = p->next;
            ++j;
        }
        ++i;
    }
}

void LinkedList::appendRandom(int round)
{
    int i = 0, rand = 0;
    // * loop with round
    while (i < round)
    {
        // * random number < 101
        rand = random() % 101;
        add(curSize, rand);
        ++i;
    }
}

void LinkedList::swap(ChainNode *p, ChainNode *q)
{
    if (isEmpty())
    {
        cerr << "[Massage Error] : memory is empty!!!" << endl;
        return;
    }

    // * just swap element function
    int t = p->element;
    p->element = q->element;
    q->element = t;
}

void LinkedList::display()
{
    // * show L to L:(?,?), size: corSize/MaxSize
    // * L: {1,2,3}
    cout << "[Massage] -> L: {";
    if (curSize == 0)
    {
        cout << "}, ";
    }
    else
    {
        ChainNode *p = firstNode->next;
        for (int i = 0; i < curSize; i++, p = p->next)
        {
            cout << p->element;
            if (i < curSize - 1)
                cout << ", ";
            else
                cout << "}, ";
        }
    }

    cout << "Size: " << curSize << endl;
}