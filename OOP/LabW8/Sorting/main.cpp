/***************************************************************************************
 * ID: 65037743
 * NAME: Mr.Kidsadakorn Nuallaoong
 * DESCRIPTION: Sorting
 ***************************************************************************************/
#include <iostream>
#include "Sorting.h"

using namespace std;

char CH(char S){
    cout << "You want to open process display? [T/F] : ";
    cin >> S;
    if(S == 'T' || S == 't' ){ S = true; } else { S = false; };
    
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
    char choice;
    // * cout << "You want to open process display? [T/F] : ";
    // * cin >> choice;

    bool select;
    select = CH(choice);
    
    sort.selection(select);

    // * { min  -> max }
    sort.diaplaySwapCounter(); 
    sort.displayLoopCounter();
    sort.displayTimeElasped();

    // * insertion
    cout << endl;
    cout << ">> Insertion <<" << endl;
    sort.restore();
    
    sort.insertion(select);

    // * { min  -> max }
    sort.diaplaySwapCounter(); 
    sort.displayLoopCounter();
    sort.displayTimeElasped();

    // * bubble
    cout << endl;
    cout << ">> Bubble <<" << endl;
    sort.restore();
    // * sort.display();
    
    sort.bubble(select);

    // * { min  -> max }
    sort.diaplaySwapCounter(); 
    sort.displayLoopCounter();
    sort.displayTimeElasped();

    return 0;
}
