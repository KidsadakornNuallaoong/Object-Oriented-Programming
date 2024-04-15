/***************************************************************************************
 * ID: 65037743
 * NAME: Mr.Kidsadakorn Nuallaoong
 * DESCRIPTION: ArrayList Testing
 ***************************************************************************************/
#include <iostream>
#include "arrayList.h"

using namespace std;

int main()
{
    ArrayList list(5);
    
    int choice,index,element;
    char select;

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
    cout << "0: Exit!!!!" << endl;
    
    cout << endl;
    
    cout << "Enter your choice : " ; cin >> choice;
    
    switch (choice)
    {
    case 1: // * add
        cout << "Enter index : "; cin >> index;
        cout << "Enter element : "; cin >> element;
        list.add(index, element);
        break;

    case 2: // * remove

        cout << "i = index" << endl;
        cout << "e = element" << endl;
        cout << "Please select : [i/e] " ; cin >> select;

        switch (select)
        {
        case 'i':
            cout << "Enter index : "; cin >> index;
            list.remove(index);
            break;

        case 'e':
            cout << "Enter element : "; cin >> element;
            list.remove(list.indexOf(element));
            break;
        }

        break;

    case 3: // * set
        cout << "Enter index : "; cin >> index;
        cout << "Enter element : "; cin >> element;
        list.set(index, element);
        break;

    case 4: // * get
        cout << "i = index" << endl;
        cout << "e = element" << endl;
        cout << "Please select : [i/e]" ; cin >> select;

        if(select == 'i'){
            cout << "Enter index : "; cin >> index;
            cout << "[Massage] list[" << index << "] is " << list.get(index) << endl;
        }else if(select == 'e'){
            cout << "Enter element : "; cin >> element;
            cout << "[Massage] list[" << index << "] is " << list.get(list.indexOf(element)) << endl;
        }

        break;

    case 5: // * index of
        cout << "Enter element : "; cin >> element;
        list.indexOf(element);
        break;

    case 6: // * list size
        cout << "[Massage] Current List Size is " << list.size() << endl; 
        break;

    case 7: // * clear
        list.clear();
        break;

    case 8: // * max
        list.max();
        break;

    case 9: // * min
        list.min(); 
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