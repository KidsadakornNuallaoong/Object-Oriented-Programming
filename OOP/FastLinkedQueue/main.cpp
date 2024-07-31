/***************************************************************************************
 * ID: 65037743
 * NAME: Mr.Kidsadakorn Nuallaoong
 * DESCRIPTION: FastLinkedQueue && Apply otherType
 ***************************************************************************************/
#include <iostream>
#include "FastLinkedQueue.h"

using namespace std;

int main()
{
    FastLinkedQueue Queue;

    int choice, index, element, round;
    float dataF;
    long dataL;
    string str;
    char *pStr;

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

        cout << "1: Add Queue, enQueue(int)" << endl;
        cout << "2: Get first , deQueue(int)" << endl;
        cout << "3: Show front Queue, front()" << endl;
        cout << "4: shoe last Queue, rear()" << endl;

        cout << "5: Add Queue, enQueue(float)" << endl;
        cout << "6: Get first , deQueue(float)" << endl;

        cout << "7: Add Queue, enQueue(long)" << endl;
        cout << "8: Get first , deQueue(long)" << endl;

        cout << "9: Add Queue, enQueue(char *)" << endl;
        cout << "10: Get first , deQueue(char *)" << endl;

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

        case 5: // * enQueue
            cout << "[Massage] Enter element : ";
            cin >> dataF;
            Queue.enQueueFloat(dataF);

            cout << "Your float is already enter queue..." << endl;
            break;

        case 6: // * pop
            dataF = Queue.deQueueFloat();
            cout << "[Massage] get element : " << dataF << endl;
            break;

        case 7: // * enQueue
            cout << "[Massage] Enter element : ";
            cin >> dataL;
            Queue.enQueueLong(dataL);

            cout << "Your long is already enter queue..." << endl;
            break;

        case 8: // * pop
            dataL = Queue.deQueueLong();
            cout << "[Massage] get element : " << dataL << endl;
            break;

        case 9: // * enQueue
            cout << "[Massage] Enter element : ";
            cin >> str;
            Queue.enQueueCString((char *)str.c_str());

            cout << "Your string is already enter queue..." << endl;
            break;

        case 10: // * pop
            pStr = Queue.deQueueCString();
            cout << "[Massage] get String : " << pStr << endl;

            // !!! free
            free(pStr);
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