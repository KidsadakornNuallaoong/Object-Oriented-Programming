#include <iostream>
#include "ChainNode.h"

using namespace std;

int main()
{
    ChainNode a; // * ==> e = 0, p = NULL
    ChainNode b(10, &a); // * ==> e = 10, p = &a
    ChainNode c(20, &b); // * ==> e = 20, p = &b
    
    return 0;
}