/***************************************************************************************
 * NAME: Mr.Kidsadakorn Nualloong
 * DESCRIPTION: ArrayList Algorithm
 ***************************************************************************************/

#include "arrayList.h"
#include <iostream>

using namespace std;

ArrayList::ArrayList(int maxSize)
{
    // * create array with maxSize element
    L = new int[maxSize];
    // * set maximum size to maxSize
    this->maxSize = maxSize;
    // * set current size to zero
    curSize = 0;
}

ArrayList::~ArrayList()
{
    // * free memory
    delete []L;
}

int ArrayList::size()
{
    // * return curren element size 
    return curSize;
}

int ArrayList::indexOf(int e)
{
    int i;
    if(curSize <= 0){
        cout << "[massage error] Empty List!!!!!" << endl;
        return -1;
    }
    // * loop before checking element of index
    for(i = 0 ; i <= curSize-1 && L[i] != e ; ++i){
            this->L[i] = L[i];
    } // * check 
    if(L[i] == e){
        cout << "[Massage] : Index of Array : {" << e << "} is [" << i << "]" << endl;
    }else{
        cout << "[Massage Warning] : Element is not found!!!" << endl;
        return -1;
    }

    return i;
}

int ArrayList::get(int i)
{
    // * check empty
    if (curSize <= 0)
    {
        cout << "[Massage Error] : List is empty!" << endl;
        return -1;
    }
    
    // * check lower
    if (i < 0)
    {
        cout << "[Massage Warning] : i is lower bound" << endl;
        cout << "[Massage] : i is changed to 0" << endl;
        i = 0;
    }
    // * check upper
    else if (i > curSize -1)
    {
        cout << "[Massage Warning] : i is over bound" << endl;
        cout << "[Massage] : i is changed to " << curSize-1 << endl;
        i = curSize -1;
    }
    // * get L[i]
    return L[i];
}

void ArrayList::set(int i, int e)
{
    // * check lower
    if (i < 0)
    {
        cout << "[Massage Warning] : Index is lower bound can't to set this element" << endl;
    }else if(i < curSize){
        // * set element e to i
        cout << "[Massage Warning] : Element " << L[i];
        L[i] = e;
        cout << " is changed " << L[i] << endl;
    }else if(i >= curSize){    
        // * check upper
        cout << "[Massage Warning] : Index is over bound can't to set this element" << endl;
    }
}

int ArrayList::remove(int i)
{
    // * check lower
    if (i < 0)
    {
        cout << "[Massage Warning] : Can't remove element this lower bound" << endl;
        return -1;
    }else if(i >= curSize){
        // * check upper
        cout << "[Massage Warning] : Can't remove element this over bound" << endl;
        return -1;
    }
    else if(i <= curSize){
        // * return value to remove
        cout << "[Massage] : Element remove is : " << L[i] << " !!!" << endl;
        // * loop to index i
        for(int j = i; j <= curSize-1; ++j){
            L[j] = L[j+1]; // * remove value index i
        }
        curSize--;
    }
    return L[i];
}

void ArrayList::add(int i, int e)
{
    // * check empty list
    if(curSize == maxSize){
        cout << "[Massage] : List is full !!!!!" << endl;
        return;
    }

    // * check lower bound
    if(i < 0){
        cout << "[Massage Warning] : Lower bound" << endl;
        cout << "[Massage] : Index is changed to 0"<< endl;
        i = 0;
    }
    // * check upper bound
    else if(i > curSize){
        cout << "[Massage Warning] : upper bound" << endl;
        cout << "[Massage] : Index is changed to "<< curSize << endl;
        i = curSize;
    }
    // * index is ok
    // * shift right from curSize -1 down to i

    for(int j = curSize -1; j >= i; j--){
        // * move element at i to i + 1
        L[j + 1] = L[j];
    }

    // * put e at i index
    L[i] = e;
    // * increment current size
    curSize++;
}

void ArrayList::clear()
{
    // * clear element in array
    /*
    while(curSize != 0){
        curSize--;
    }
    */
    curSize = 0;
    cout << "[Massage] : Array is clear" << endl;
}

int ArrayList::max()
{
    int result = 0;
    // * check empty list
    if(curSize <= 0){
        cout << "[Massage Error] : Array is Empty!!!!" << endl;
        cout << "[Massage] Can't find max value" << endl;
        return -1;

    }else if(curSize < 2){
        result = L[curSize-1]; // * check first index and set index 1

        cout << "[Massage] : MaxValue is " << result << endl;
        return -1;

    }
    // * find max value in array
        for(int i = 0; i < curSize; ++i){
            if(result < L[i]){
                result = L[i];
            }
        }

    cout << "[Massage] : MaxValue is " << result << endl;
    
    return result;
}

int ArrayList::min()
{
    int result;
    // * check empty list
    if(curSize <= 0){
        cout << "[Massage Error] : Array is Empty!!!!" << endl;
        cout << "[Massage] Can't find min value" << endl;
        return -1;

    }else if(curSize < 2){ // * check first index and set index 1
        result = L[curSize-1];

        cout << "[Massage] : MinValue is " << result << endl;
        return -1;

    }
    // * find min value in array
    int i = 0;
    result = L[i];
    do
    {
       if(result > L[i])
            result = L[i];
        ++i;

    }while(i < curSize);

    cout << "[Massage] : MinValue is " << result << endl;

    return result;
}

/*int ArrayList::max()
{
    // * find max value in array
    int result = 0;
    for(int i = 0; i < curSize; ++i){
        if(result < L[i]){
            result = L[i];
        }
    }
    if(result == 0){
        cout << "[Massage] : Value is [0] no Max/min" << endl;
    }
    cout << "[Massage] : MaxValue is " << result << endl;
    return result;
}

int ArrayList::min()
{
    // * find min value in array
    int i = 0;
    int result = L[i];
    do
    {
       if(result > L[i]){
            result = L[i];
        } 
        i++;
    }while(i < curSize);
    if(result == 0){
        cout << "[Massage] : Value is 0 no Max/min" << endl;
    }
    cout << "[Massage] : MinValue is " << result << endl;
    return result;
}
*/
void ArrayList::display()
{
    // * show L to L:(?,?), size: corSize/MaxSize
    // * L: {1,2,3}
    cout << "[Massage] -> L: {";
    if(curSize <= 0){
        cout << "}, ";
    }else
    for( int i = 0 ; i < curSize ; ++i ){
        cout << L[i];
        if(i < curSize - 1)
            cout << ", ";
        else
            cout << "}, ";
    }

    cout << "Size: " << curSize << "/" << maxSize << endl; 
}