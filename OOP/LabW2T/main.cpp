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
    ArrayList list(5); // * call => arraylist(5)
    int e = list.get(5);  // * call element at index 5
    cout << "e[5] " << e << endl;

    list.add(0,10); // * add (index, element to add in array)
    list.display(); // * show array to display {element, element}

    list.add(-3,20); 
    list.display();

    list.add(10,30);
    list.display();

    list.add(2,40);
    list.display();

    list.add(0,50);
    list.display();

    list.add(0,60);
    list.display();

    cout << endl; // * endline

    list.max(); // * find max value
    list.min(); // * find min value

    cout << endl;

    // ! Example if wrong input
    e = list.get(-1);
    cout << "e[-1] " << e << endl;

    e = list.get(10); 
    cout << "e[10] " << e << endl;

    cout << endl;

    cout << "Current List Size is " << list.size() << endl; // * show size / cursize from class

    cout << endl;

    list.remove(4); // * remove element by index
    list.remove(3);

    list.display(); 

    list.remove(1);

    list.display();

    list.remove(7);
    list.remove(-1);
    list.display();

    cout << endl;

    e = list.get(0);
    cout << "e[0] " << e << endl;

    // ! set element to index (index , element)
    list.set(0,200); 
    list.set(-1,300);
    list.set(1,135);
    list.set(2,150);
    list.display();

    cout << endl;

    // * call elemen 200 at array to find index of this element
    list.indexOf(200);
    list.indexOf(135);
    list.indexOf(132);
    list.max();
    list.min();
    list.display();

    cout << endl;

    list.clear(); // * clear all element at array
    list.display();
    list.clear();
    cout << "Current List Size is " << list.size() << endl;

    cout << endl;

    e = list.get(5);
    cout << "e[5] " << list.get(5) << endl;
    
    return 0;
}