#if !defined(_BINARYSEARCHTREE_H)
#define _BINARYSEARCHTREE_H

#include "../BinaryTreeNode/BinaryTreeNode.h"

enum ORDER{PRE_ORDER, IN_ORDER, POST_ORDER};

class BinarySearchTree
{
private:
    BinaryTreeNode *root;
    
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int e);
    void remove(); // * [option]

    int findMin(); // * done
    int findMax(); // * done

    int findDepth(); // * done

    void display(ORDER o = IN_ORDER); // * done

private:
    void insert(BinaryTreeNode *p, int e); // * done
    
    int findMin(BinaryTreeNode *p); // * done
    int findMax(BinaryTreeNode *p); // * done

    int findDepth(BinaryTreeNode *p, int d); // * done
    
    void removeTree(BinaryTreeNode *&p); // * done

    void displayPreOrder(BinaryTreeNode *p); // * done 
    void displayInOrder(BinaryTreeNode *p); // * done
    void displayPostOrder(BinaryTreeNode *p); // * done
};

#endif // _BINARYSEARCHTREE_H
