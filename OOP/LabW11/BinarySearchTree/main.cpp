/***************************************************************************************
 * ID: 65037743
 * NAME: Mr.Kidsadakorn Nuallaoong
 * DESCRIPTION: BinarySearchTree
 ***************************************************************************************/
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

#define NodeType IN_ORDER

int main(void)
{
    BinarySearchTree BST;
    int choice,Element;

do
{
    cout << "----------------- MENU -----------------" << endl << endl;

    cout << "================ DISPLAY ===============" << endl << endl;

    BST.display(NodeType);

    cout << endl << "========================================" << endl << endl;
    
    cout << "1: Insert element" << endl;
    cout << "2: remove tree" << endl;
    cout << "3: Find max" << endl;
    cout << "4: Find min" << endl;
    cout << "5: Find Depth" << endl;
    
    cout << "0: Exit!!!!" << endl;
    
    cout << endl;
    
    cout << "Enter your choice : " ; cin >> choice;
    
    switch (choice)
    {
    case 1: // * add
        cout << "Enter Element : "; cin >> Element;
        BST.insert(Element);
        break;

    case 2:
        BST.remove();
        break;

    case 3: // * find max
        cout << "Max : ";
        cout << BST.findMax() << endl;
        break;

    case 4: // * find min
        cout << "min : ";
        cout << BST.findMin() << endl;
        break;

    case 5: // * find Depth
        cout << "Depth : ";
        cout << BST.findDepth() << endl;
        break;

    case 0:
        cout << "Bye...." << endl << endl;
        cout << "-------------- Call method --------------" << endl;
        break;

    default: // * Exit
        cout << "[Massage] Wrong choice,try again..." << endl;
    }

}while(choice != 0);
}