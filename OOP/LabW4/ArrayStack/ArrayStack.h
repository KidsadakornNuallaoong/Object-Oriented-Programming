#if !defined(_ARRAYSTACK_H)
#define _ARRAYSTACK_H

#include "../ArrayList/arrayList.h"

#define DEFAULT_STACK_SIZE 5

class ArrayStack : public ArrayList
{
    private:
        int maxSize;

    public:
        ArrayStack(int maxSize = DEFAULT_STACK_SIZE);
        // ~ArrayStack();

        void push(int e);
        int pop();
        int top();

        bool isEmpty();
        bool isFull();

        void swapTopTwo();
        void moveMaxToTop();
        void sortStack();
        void flip();
};

#endif // _ARRAYSTACK_H
