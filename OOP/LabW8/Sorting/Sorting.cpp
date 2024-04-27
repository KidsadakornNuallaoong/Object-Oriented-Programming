#include "Sorting.h"
#include <iostream>

using namespace std;

Sorting::Sorting(int maxSize)
{
    this->maxSize = maxSize; // * save maxSize

    Data = new ArrayList(this->maxSize);
    temp = new ArrayList(this->maxSize);

    for (int i = 0; i < this->maxSize; ++i)
    {
        // * fill all -> 0
        Data->add(i,0);
        temp->add(i,0);
    }
}

Sorting::~Sorting()
{
    delete Data; // * Clear Data from memory
    delete temp; // * Clear Data from memory
}

void Sorting::display()
{
    // * how i display this data
    // *  Data: {e0, e1 , e2, ... , en-1}
    cout << "Data: {";
    if(maxSize <= 0){
        cout << "}" << endl;
    } else {
        for (int i = 0; i < maxSize; ++i)
        {
            cout << Data->get(i);
            if(i < maxSize-1){
                cout << ", ";
            } else {
                cout << "}" << endl;
            }
        }
    }
}

void Sorting::displayTimeElasped()
{
    // * cout << "Time: " << timeElasped << " Second" << endl;
    printf("Time: %f Second\n", timeElasped);
}

void Sorting::displayLoopCounter()
{
    cout << "Loop: " << loopCounter << " Times" << endl;
}

void Sorting::diaplaySwapCounter()
{
    cout << "Swap: " << SwapCounter << " Times" << endl;
}

void Sorting::random()
{
    for(int i = 0; i < maxSize; ++i){
        Data->set(i, rand()%100);
    }
}

void Sorting::backUp()
{
    // * set back up
    for(int i = 0;i < maxSize; ++i){
        temp->set(i, Data->get(i));
    }
}

void Sorting::restore()
{
    // * set back up
    for(int i = 0; i < maxSize; ++i){
        Data->set(i, temp->get(i));
    }
}

void Sorting::selection(bool verbose)
{
    timeElasped = 0.0;
    SwapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // * ------------ begin ------------
    // * set number of element [n, n-1,..., 2]
    for(int nElement = maxSize; nElement > 1; --nElement){
        // * find index of maximum value
        int maxIndex = findMaxIndex(nElement);
        swap(maxIndex, nElement - 1);
        
        if(verbose == true){
            display();
        }
        
    }
    // * ------------ end ------------

    clock_t end = clock();
    timeElasped = (double)(end - begin) / (double)CLOCKS_PER_SEC;
}

int Sorting::findMaxIndex(int n)
{
    // * first set max index at zero position
    int maxIndex = 0;
    // * scan for index of maximum value
    for(int i = 1; i < n; ++i){
        if(Data->get(maxIndex) < Data->get(i))
            maxIndex = i;

            loopCounter++;
    }
    // * return index of maximum value
    return maxIndex;
}

void Sorting::swap(int i, int j)
{
    // * swap as triangle copy
    // * move position array Data 
    int temp = Data->get(i);
    Data->set(i, Data->get(j));
    Data->set(j, temp);

    SwapCounter++;
}

void Sorting::insertion(bool verbose)
{
    timeElasped = 0.0;
    SwapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // * ------------ begin ------------
    // * set number of element [2, 3,..., n]
    for(int nData = 2; nData <= maxSize; ++nData){
        // * do insertion only for nData elements
        insert(nData);

        if(verbose == true){
            display();
        }
    }
    // * ------------ end ------------
    clock_t end = clock();
    timeElasped = (double)(end - begin) / (double)CLOCKS_PER_SEC;
}

void Sorting::insert(int n)
{
    // * pick insert data at index n -1 
    int insertData = Data->get(n-1);
    // * set insert index to n -2
    int insertPos = n - 2;
    // * check insertion condition
    while(insertPos >= 0 && Data->get(insertPos) > insertData){
        swap(insertPos, insertPos+1);
        insertPos--;

        loopCounter++;
    }
}

void Sorting::bubble(bool verbose)
{
    timeElasped = 0.0;
    SwapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // * ------------ begin ------------
    // * set number of element [n, n-1,....., 2]
    for(int nData = maxSize; nData > 1; --nData){
        // * do bubble only for nData elements
        bubble_(nData);

        if(verbose == true){
            display();
        }
    }
    // * ------------ end ------------
    clock_t end = clock();
    timeElasped = (double)(end - begin) / (double)CLOCKS_PER_SEC;
}

void Sorting::bubble_(int n)
{
    // * do bubble for n elements
    for(int i = 0; i < n-1; ++i){
        // * check condition for swapping
        if(Data->get(i) > Data->get(i+1))
            swap(i, i+1);

            loopCounter++;
    }
}
