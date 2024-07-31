#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(int element, BinaryTreeNode *Left, BinaryTreeNode *Right)
{
    this->element = element;
    this->Left = Left;
    this->Right = Right;
}