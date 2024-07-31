/***************************************************************************************
 * ID: 65037743
 * NAME: Mr.Kidsadakorn Nuallaoong
 * DESCRIPTION: LinkStack Testing
 ***************************************************************************************/
#include <iostream>
#include "LinkStack.h"

using namespace std;

int main()
{
    LinkStack Stack;

    int choice, index, element, round;

    do
    {
        cout << "----------------- MENU -----------------" << endl
             << endl;

        cout << "================ DISPLAY ===============" << endl
             << endl;

        Stack.display();

        cout << endl
             << "========================================" << endl
             << endl;

        cout << "1: Add element to last Stack, push()" << endl;
        cout << "2: Get last element, pop()" << endl;
        cout << "3: Get top element, top()" << endl;
        cout << "4: Clear element in Stack, clear()" << endl;

        cout << "5: Check size of Stack is Empty?, isEmpty()" << endl;
        cout << "6: Check size of Stack is Full?, isFull()" << endl;
        cout << "7: Find maximum number from Stack, max()" << endl;
        cout << "8: Find minimum number from Stack, min()" << endl;

        cout << "9. Random and add to Stack, appendRandom()" << endl;
        cout << "10. Swap two element on pop, swapToTwo()" << endl;
        cout << "11. move element to top Stack, moveToTop()" << endl;

        cout << "12: Find odd number from list, oddcount()" << endl;
        cout << "13: Find even number from list, evencount()" << endl;
        cout << "14: Find sum value, sum()" << endl;
        cout << "15: Calculate average value from list, mean()" << endl;

        cout << "16. Sorting and stacking low to high, sortStack()" << endl;
        cout << "17. flip list, flip()" << endl;

        cout << "0: Exit!!!!" << endl;

        cout << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1: // * push
            cout << "[Massage] Enter element : ";
            cin >> element;
            Stack.push(element);
            break;

        case 2: // * pop
            element = Stack.pop();
            cout << "[Massage] get element : " << element << endl;
            break;

        case 3: // * top
            element = Stack.top();
            cout << "[Massage] Element on top : " << element << endl;
            break;

        case 4: // * clear
            Stack.clear();
            break;

        case 5:
            if(Stack.isEmpty() != false){
                cout << "[Massage] is empty!!!" << endl;
            }else{
                cout << "[Massage] Can't add Stack!!!" << endl;
            }
            break;
        
        case 6:
            if(Stack.isFull() != false){
                cout << "[Massage] is Full!!!" << endl;
            }else{
                cout << "[Massage] Can add Stack!!!" << endl;
            }
            break;

        case 7: // * max
            element = Stack.max();
            cout << "[Massage] : MaxValue is : " << element << endl;
            break;

        case 8: // * min
            element = Stack.min();
            cout << "[Massage] : MinValue is : " << element << endl;
            break;

        case 9: // * appendrandom
            cout << "Enter number of numbers : ";
            cin >> round;
            Stack.appendRandom(round);
            break;

        case 10: // * swapToTwo
            Stack.swapTopTwo();
            break;

        case 11: // * moveToTop
            Stack.moveMaxToTop();
            break;

        case 12: // * oddcount
            element = Stack.oddCount();
            cout << "[Massage] Odd counting " << element << endl;
            break;

        case 13: // * evencount
            element = Stack.evenCount();
            cout << "[Massage] Even counting " << element << endl;
            break;

        case 14:
            element = Stack.sum();
            cout << "[Massage] Summation is " << element << endl;
            break;

        case 15:
            element = Stack.mean();
            cout << "[Massage] Mean is " << element << endl;
            break;

        case 16:
            Stack.sortStack();
            break;

        case 17: // * moveToTop
            Stack.flip();
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