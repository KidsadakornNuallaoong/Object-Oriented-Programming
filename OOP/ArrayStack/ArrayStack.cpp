#include "ArrayStack.h"

ArrayStack::ArrayStack(int maxSize) : ArrayList(maxSize)
{
    // * set maxSize = maxSize
    this->maxSize = maxSize;
}

void ArrayStack::push(int e)
{
    // * add to element
    add(size(), e);
}

int ArrayStack::pop()
{
    // * remove element index Size - 1
    return remove(size() - 1);
}

int ArrayStack::top()
{
    // * get element index Size - 1
    return get(size() - 1);
}

bool ArrayStack::isEmpty()
{
    return size() == 0;
}

bool ArrayStack::isFull()
{
    return size() == DEFAULT_STACK_SIZE;
}

void ArrayStack::swapTopTwo()
{
    // * get and remove element
    // * We can use pop(); ---> 2 line 
    int a = remove(size() - 1);
    int b = remove(size() - 1);
    
    // * add element to first index
    // * We can use push(element); ---> 2 line
    add(size(), a);
    add(size(), b);
}

void ArrayStack::moveMaxToTop()
{
    // * find max value
    int a = max();
    // * get and remove max stack
    remove(indexOf(max()));
    // * add element a to last index
    push(a);
}

void ArrayStack::sortStack()
{
    // * get sorting
    sort();
}

void ArrayStack::flip()
{
    int j = size() - 1;

    for (j; j > 0; --j)
    {
        // * get and remove element index[0]
        // * add element to j-1/r
        add(j, remove(0));
    }
}