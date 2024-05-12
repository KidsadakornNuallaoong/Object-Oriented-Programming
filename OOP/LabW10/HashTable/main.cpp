/***************************************************************************************
 * ID: 65037743
 * NAME: Mr.Kidsadakorn Nuallaoong
 * DESCRIPTION: HashTable
 ***************************************************************************************/
#include <iostream>
#include "HashTable.h"

using namespace std;

int main(void)
{
    HashTable Hash;
    int choice,key;

do
{
    cout << "----------------- MENU -----------------" << endl << endl;

    cout << "================ DISPLAY ===============" << endl << endl;

    Hash.display();

    cout << endl << "========================================" << endl << endl;
    
    cout << "1: Add key" << endl;
    cout << "2: Search key" << endl;
    
    cout << "0: Exit!!!!" << endl;
    
    cout << endl;
    
    cout << "Enter your choice : " ; cin >> choice;
    
    switch (choice)
    {
    case 1: // * add
        cout << "Enter key : "; cin >> key;
        Hash.addkey(key);
        break;

    case 2: // * remove
        cout << "Enter search key : "; cin >> key;
        Hash.searchkey(key);
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