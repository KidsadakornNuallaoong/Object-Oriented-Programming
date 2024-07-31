/***************************************************************************************
 * ID: 65037743
 * NAME: Mr.Kidsadakorn Nuallaoong
 * DESCRIPTION: Sorting
 ***************************************************************************************/
#include <iostream>
#include "Sorting.h"
#include "../ArrayList/arrayList.h"

using namespace std;

char CH(char S)
{
    cout << "You want to open process display? [T/F] : ";
    cin >> S;
    if (S == 'T' || S == 't')
    {
        S = true;
    }
    else
    {
        S = false;
    };

    return S;
}

int main()
{
    Sorting sort;
    sort.random();
    sort.backUp(); // * Data --> temp

    // * selection
    cout << ">> Selection <<" << endl;

    sort.restore();
    // * sort.display();
    int choice;
    // * cout << "You want to open process display? [T/F] : ";
    // * cin >> choice;

    do
    {
        cout << "----------------- MENU -----------------" << endl
             << endl;

            bool select;
            select = CH(choice);

        cout << endl << "================ DISPLAY ===============" << endl
             << endl;

        sort.display();

        cout << endl
             << "========================================" << endl
             << endl;

        cout << "1: Selection Sort, selection()" << endl;
        cout << "2: Insertion Sort, insertion()" << endl;
        cout << "3: Bubble Sort, bubble()" << endl;

        cout << "4: Shell Sort, shell()" << endl;
        cout << "5: Merge Sort, merge()" << endl;
        cout << "6: Quick Sort, quick()" << endl;

        cout << "0: Exit!!!!" << endl;

        cout << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1: // * selection
            sort.selection(select);

            sort.diaplaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElasped();
            break;

        case 2: // * insertion
            sort.insertion(select);

            sort.diaplaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElasped();
            break;

        case 3: // * bubble
            sort.bubble(select);

            sort.diaplaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElasped();
            break;

        case 4: // * shell
            sort.shell(select);
            
            sort.diaplaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElasped();
            break;

        case 5: // * Sort
            sort.merge();
            
            sort.diaplaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElasped();
            break;

        case 6: // * Sort
            sort.quick(select);
            
            sort.diaplaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElasped();
            break;

        case 7:
            sort.reRandom();

        case 0:
            cout << "Bye...." << endl
                 << endl;
            cout << "-------------- Call method --------------" << endl;
            break;

        default: // * Exit
            cout << "[Massage] Wrong choice,try again..." << endl;
        }

    } while (choice != 0);

    return 0;
}