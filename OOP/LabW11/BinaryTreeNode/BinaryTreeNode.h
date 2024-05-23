#if !defined(_BINARYTREENODE_H)
#define _BINARYTREENODE_H

#include <iostream>

class BinaryTreeNode
{
public:
    int element;
    BinaryTreeNode *Left;
    BinaryTreeNode *Right;
public:
    BinaryTreeNode(int element = 0,
                    BinaryTreeNode *Left = NULL,
                    BinaryTreeNode *Right = NULL);
};

#endif // _BINARYTREENODE_H
