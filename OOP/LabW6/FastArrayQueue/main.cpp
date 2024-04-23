/***************************************************************************************
 * ID: 65037743
 * NAME: Mr.Kidsadakorn Nuallaoong
 * DESCRIPTION: FastArrayQueue
 ***************************************************************************************/
#include <iostream>
#include "FastArrayQueue.h"

using namespace std;

int main()
{
    FastArrayQueue Queue;

    int choice, index, element, round;

    do
    {
        cout << "----------------- MENU -----------------" << endl
             << endl;

        cout << "================ DISPLAY ===============" << endl
             << endl;

        Queue.display();

        cout << endl
             << "========================================" << endl
             << endl;

        cout << "1: Add Queue, enQueue()" << endl;
        cout << "2: Get first , deQueue" << endl;
        cout << "3: Show front Queue, front()" << endl;
        cout << "4: shoe last Queue, rear()" << endl;

        cout << "0: Exit!!!!" << endl;

        cout << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1: // * enQueue
            cout << "[Massage] Enter element : ";
            cin >> element;
            Queue.enQueue(element);
            break;

        case 2: // * pop
            element = Queue.deQueue();
            cout << "[Massage] get element : " << element << endl;
            break;

        case 3: // * top
            element = Queue.front();
            cout << "[Massage] front element : " << element << endl;
            break;

        case 4: // * top
            element = Queue.rear();
            cout << "[Massage] Last element : " << element << endl;
            break;

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