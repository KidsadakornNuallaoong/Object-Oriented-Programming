#if !defined(_LINKSTACK_H)
#define _LINKSTACK_H

#include "../LinkedList/LinkedList.h"

class LinkStack : public LinkedList
{
    private:
        int maxSize;

    public:
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

#endif // _LINKSTACK_H