#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    // * set tree
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    // * delete tree
    if(root != NULL) removeTree(root);
}

void BinarySearchTree::insert(int e)
{
    // * BST constrain: L < R
    if(root == NULL){
        root = new BinaryTreeNode(e);
    } else {
        insert(root, e);
    }

}

void BinarySearchTree::remove()
{
    if(root != NULL){
        removeTree(root);
    }
}

int BinarySearchTree::findMin()
{
    return findMin(root);
}

int BinarySearchTree::findMax()
{
    return findMax(root);
}

int BinarySearchTree::findDepth()
{
    return findDepth(root, 0);
}

int BinarySearchTree::findMin(BinaryTreeNode *p)
{
    return p->element;
}

int BinarySearchTree::findMax(BinaryTreeNode *p)
{
    if(p->Right != NULL) // * if Tree not NULL go to root(left/right)
        return findMax(p->Right);
    else
        return p->element;
}

int BinarySearchTree::findDepth(BinaryTreeNode *p, int d)
{
    int lDepth = d;
    int rDepth = d;

    // * find left depth (recursive)
    if(p->Left != NULL) lDepth = findDepth(p->Left, d + 1);

    // * find right depth (recursive)
    if(p->Right != NULL) rDepth = findDepth(p->Right, d + 1);

    // * return max(ld, rd);
    return (lDepth > rDepth ? lDepth : rDepth);
}

void BinarySearchTree::insert(BinaryTreeNode *p, int e)
{
    // * p not NULL
    // * L < n <= R
    if(e < p->element){
        if(p->Left == NULL) p->Left = new BinaryTreeNode(e);
        else insert(p->Left, e); 
    } else {
        if(p->Right == NULL) p->Right = new BinaryTreeNode(e);
        else insert(p->Right, e); 
    }
}

void BinarySearchTree::removeTree(BinaryTreeNode *&p)
{
    // * started p->root left/right check == NULL? if not p->root left/right
    // * if == NULL get delete tree(p)

    if(p != NULL){
    // * remove left subtree
    if(p->Left != NULL) removeTree(p->Left);
    // * remove right subtree
    if(p->Right != NULL) removeTree(p->Right);

    // * remove node
    delete p;

    // * set p to nothing
    p = NULL; // *&p (allow to self-editable)
              // * no error but effect to
    }
}

void BinarySearchTree::displayPreOrder(BinaryTreeNode *p)
{
    // * (n, L, R)
    // * ...

    cout << "(";

    cout << p->element;

    cout << ",";

    if(p->Left != NULL) displayPreOrder(p->Left); else cout << "-";

    cout << ",";

    if(p->Right != NULL) displayPreOrder(p->Right); else cout << "-";

    cout << ")";
}

void BinarySearchTree::displayInOrder(BinaryTreeNode *p)
{
    // * (L, n, R)
    cout << "(";
    if(p->Left != NULL) displayInOrder(p->Left); else cout << "-";

    cout << ",";

    cout << p->element;

    cout << ",";

    if(p->Right != NULL) displayInOrder(p->Right); else cout << "-";

    cout << ")";
}

void BinarySearchTree::displayPostOrder(BinaryTreeNode *p)
{
    // * (L, R, n)
    // * ...

    cout << "(";
    
    if(p->Left != NULL) displayPostOrder(p->Left); else cout << "-";

    cout << ",";

    if(p->Right != NULL) displayPostOrder(p->Right); else cout << "-";

    cout << ",";
    
    cout << p->element;

    cout << ")";
}


void BinarySearchTree::display(ORDER o)
{
    if(root == NULL){
        cout << "Tree: -"; 
    } else {
        cout << "Tree: ";
        if(o  ==  PRE_ORDER)
            displayPreOrder(root);
        else if(o == POST_ORDER)
            displayPostOrder(root);
        else // * defualt case
            displayInOrder(root);

        cout << endl;
    }
}
