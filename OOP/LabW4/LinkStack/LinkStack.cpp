#include "LinkStack.h"

void LinkStack::push(int e)
{
    // * add to element
    add(size(), e);
}

int LinkStack::pop()
{
    // * remove element index Size - 1
    return remove(size() - 1);
}

int LinkStack::top()
{
    // * get element index Size - 1
    return get(size() - 1);
}

bool LinkStack::isEmpty()
{
    return LinkedList::isEmpty();
}

bool LinkStack::isFull()
{
    return LinkedList::isFull();
}

void LinkStack::swapTopTwo()
{
    // * get and remove element
    int a = remove(size() - 1);
    int b = remove(size() - 1);

    // * add element to first index
    add(size(), a);
    add(size(), b);
}

void LinkStack::moveMaxToTop()
{
    // * find max value
    int a = max();
    // * get and remove max stack
    remove(indexOf(max()));
    // * add element a to last index
    push(a);
}

void LinkStack::sortStack()
{
    // * get sorting
    sort();
}

void LinkStack::flip()
{
    int j = size() - 1;

    for (j; j > 0; --j)
    {
        // * get and remove element index[0]
        // * add element to j-1/r
        add(j, remove(0));
    }
}