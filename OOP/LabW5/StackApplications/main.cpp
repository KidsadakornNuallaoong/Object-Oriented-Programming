/***************************************************************************************
 * ID: 65037743
 * NAME: Mr.Kidsadakorn Nuallaoong
 * DESCRIPTION: StackApplications
 ***************************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include "../LinkStack/LinkStack.h"

using namespace std;

int presedence(char c)
{
    // * get point of important for operator
    switch (c)
    {
    case '+':
    case '_':
        return 0;

    case '*':
    case '/':
        return 1;

    case '^':
        return 2;

    default:
        return -1;
    }
}

int main(void)
{
    LinkStack Stack;
    // * operators '+', '_', '*', '/', '^', '(', ')'
    // * operands: 0, 1, ..., 9

    // * ex. "3 + 5" => "35+"
    // *string infix = "((3+6)*4/2-2^3)/5";
    string infix = "2^(1+4/2)^2";
    string postfix = "";
    int result = 0;

    // * display infix
    cout << "infix: " << infix << endl;

    // * 1.infix to postfix econversion (p.11)

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        // * check operands
        if (c >= '0' && c <= '9')
        {
            postfix += c;
        }
        // * checking operator
        else if (c == '+' || c == '-' ||
                 c == '*' || c == '/' ||
                 c == '^' ||
                 c == '(' || c == ')')
        {
            // * check stack isEmpty!!!
            if (Stack.isEmpty())
            {
                Stack.push(c);
            }
            else
            {
                // * find operand in String
                // * but sorting work process / Stacking
                // * Ex. 3+5 = 35+ --> logic
                if (c == '(')
                {
                    Stack.push(c);
                }
                else if (c == ')')
                {
                    char temp;
                    do
                    {
                        temp = (char)Stack.pop();
                        if (temp != '(')
                        {
                            postfix += temp;
                        }
                    } while (temp != '(');
                }
                // * checking wrong process ----> sorting by important
                else if (presedence(c) > presedence(Stack.top()))
                {
                    Stack.push(c);
                }
                else if (presedence(c) <= presedence(Stack.top()))
                {
                    postfix += (char)Stack.pop();
                    Stack.push(c);
                }
            }
        }
    }

    // * set new string without ()
    while (!Stack.isEmpty())
    {
        // * get operand to postfix
        postfix += (char)Stack.pop();
    }

    // * display postfix
    cout << "Postfix : " << postfix << endl;

    // * 2.postfix calculation (p.31)
    // * 2.1 loop for all postfix
    for (int i = 0; i < postfix.length(); ++i)
    {
        if ((char)postfix[i] >= '0' && (char)postfix[i] <= '9')
        {
            // * push operand to Stack
            Stack.push(postfix[i] - 48);
        }
        // * check opeator in array string
        // * if array string have operator move to calculate
        else if ((char)postfix[i] == '+' || (char)postfix[i] == '-' ||
                 (char)postfix[i] == '*' || (char)postfix[i] == '/' ||
                 (char)postfix[i] == '^' || (char)postfix[i] == '(' ||
                 (char)postfix[i] == ')')
        {
            int Sa = Stack.pop(); // * get last Stack
            int Sb = Stack.pop(); // * get almost the top of Stack
            // * Check operator for calculate
            switch ((char)postfix[i])
            {
            case '+':
                // * almost the top of Stack + last Stack
                Stack.push(Sb + Sa);
                break;

            case '-':
                // * almost the top of Stack - last Stack
                Stack.push(Sb - Sa);
                break;

            case '*':
                // * almost the top of Stack * last Stack
                Stack.push(Sb * Sa);
                break;

            case '/':
                // * almost the top of Stack / last Stack
                Stack.push(Sb / Sa);
                break;

            case '^':
                // * almost the top of Stack ^ last Stack
                Stack.push(pow(Sb, Sa));
                break;
            }
        }
        // * checking work proceess
        // * Stack.display();
    }

    // * set result = reemaining
    result = Stack.pop(); // * (char)ascii number

    // * display result
    cout << "result : " << result << endl;
}