#include <iostream>
#include "ChainNode.h"

ChainNode::ChainNode(int e, ChainNode *p)
{
    element = e;
    next = p;
}