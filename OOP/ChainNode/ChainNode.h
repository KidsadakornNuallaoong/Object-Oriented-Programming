#if !defined(_CHAINNODE_H)
#define _CHAINNODE_H

#include <iostream>

class ChainNode
{    
    public:
        int element;
        ChainNode *next;
    public:
        ChainNode(int e = 0, ChainNode *p = NULL);
};

#endif // _CHAINNODE_H
