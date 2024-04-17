/***************************************************************************************
 * ID: 65037743
 * NAME: Mr.Kidsadakorn Nuallaoong
 * DESCRIPTION: LinkList Testing
 ***************************************************************************************/
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    int choice,index,element, round;
    LinkedList list;
do
{
    cout << "----------------- MENU -----------------" << endl << endl;

    cout << "================ DISPLAY ===============" << endl << endl;

    list.display();

    cout << endl << "========================================" << endl << endl;
    
    cout << "1: Add element to List, add()" << endl;
    cout << "2: Remove element from list, remove()" << endl;
    cout << "3: Set element to list, set()" << endl;
    cout << "4: Get element from list, get()" << endl;
    cout << "5: Index of element, indexOf()" << endl;
    cout << "6: List size, size()" << endl;
    cout << "7: Clear list, clear()" << endl;
    cout << "8: Find maximum number from list, max()" << endl;
    cout << "9: Find minimum number from list, min()" << endl;
    cout << "10: Find odd number from list, oddcount()" << endl;
    cout << "11: Find even number from list, evencount()" << endl;
    cout << "12: Find sum value, sum()" << endl;
    cout << "13: Calculate average value from list, mean()" << endl;
    cout << "14: Sorting element, sort()" << endl;
    cout << "15: Append random number to list, appendRandom()" << endl;
    cout << "0: Exit!!!!" << endl;

    cout << "----------------- INPUT -----------------" << endl << endl;
    
    cout << "Enter your choice : " ; cin >> choice;
    
    switch (choice)
    {
    case 1: // * add
        cout << "Enter index : "; cin >> index;
        cout << "Enter element : "; cin >> element;
        list.add(index, element);
        break;

    case 2: // * remove
        cout << "Enter index : "; cin >> index;
        element = list.remove(index);
        cout << "[Massage] : Remove -> " << element << endl;
        break;

    case 3: // * set
        cout << "Enter index : "; cin >> index;
        cout << "Enter element : "; cin >> element;
        list.set(index, element);
        break;

    case 4: // * get
        cout << "Enter index : "; cin >> index;
        element = list.get(index);
        cout << "[Massage] list[" << index << "] is " << element << endl;
        break;

    case 5: // * index of
        cout << "Enter element : "; cin >> element;
        index = list.indexOf(element);
        cout << "[Massage] : Index of Element " << element << " is : " << index << endl;
        break;

    case 6: // * list size
        cout << "[Massage] Current List Size is " << list.size() << endl; 
        break;

    case 7: // * clear
        list.clear();
        break;

    case 8: // * max
        element = list.max();
        cout << "[Massage] : MaxValue is : " << element << endl;
        break;

    case 9: // * min
        element = list.min();
        cout << "[Massage] : MinValue is : " << element << endl;
        break;
    
    case 10: // * odd
        element = list.oddCount();
        cout << "[Massage] : Odd number -> " << element << endl; 
        break;

    case 11: // * even
        element = list.evenCount();
        cout << "[Massage] : Even number -> " <<  element << endl;
        break;

    case 12: // * sum value
        element = list.sum(); 
        cout << "[Massage] : Summation is " << element << endl;
        break;

    case 13: // * mean
        element = list.mean(); 
        cout << "[Massage] : Average is " << element << endl;
         
        break;

    case 14: // * sort
        list.sort(); 
        break;

    case 15: // * appendRandom
        cout << "[massage] : Round to random number : "; cin >> round; 
        list.appendRandom(round); 
        break;

    case 0:
        cout << "Bye...." << endl << endl;
        cout << "-------------- Call method --------------" << endl;
        break;

    default: // * Exit
        cout << "[Massage] Wrong choice,try again..." << endl;
    }

}while(choice != 0);

    return 0;
}