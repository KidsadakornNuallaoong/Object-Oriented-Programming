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
        Data->add(i, 0);
        temp->add(i, 0);
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
    if (maxSize <= 0)
    {
        cout << "}" << endl;
    }
    else
    {
        for (int i = 0; i < maxSize; ++i)
        {
            cout << Data->get(i);
            if (i < maxSize - 1)
            {
                cout << ", ";
            }
            else
            {
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
    for (int i = 0; i < maxSize; ++i)
    {
        Data->set(i, rand() % 100);
    }
}

void Sorting::backUp()
{
    // * set back up
    for (int i = 0; i < maxSize; ++i)
    {
        temp->set(i, Data->get(i));
    }
}

void Sorting::restore()
{
    // * set back up
    for (int i = 0; i < maxSize; ++i)
    {
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
    for (int nElement = maxSize; nElement > 1; --nElement)
    {
        // * find index of maximum value
        int maxIndex = findMaxIndex(nElement);
        swap(maxIndex, nElement - 1);

        if (verbose == true)
        {
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
    for (int i = 1; i < n; ++i)
    {
        if (Data->get(maxIndex) < Data->get(i))
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
    for (int nData = 2; nData <= maxSize; ++nData)
    {
        // * do insertion only for nData elements
        insert(nData);

        if (verbose == true)
        {
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
    int insertData = Data->get(n - 1);
    // * set insert index to n -2
    int insertPos = n - 2;
    // * check insertion condition
    while (insertPos >= 0 && Data->get(insertPos) > insertData)
    {
        swap(insertPos, insertPos + 1);
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
    for (int nData = maxSize; nData > 1; --nData)
    {
        // * do bubble only for nData elements
        bubble_(nData);

        if (verbose == true)
        {
            display();
        }
    }
    // * ------------ end ------------
    clock_t end = clock();
    timeElasped = (double)(end - begin) / (double)CLOCKS_PER_SEC;
}

void Sorting::shell(bool verbose)
{
    timeElasped = 0.0;
    SwapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // * ------------ begin ------------
    // * do shell for k = [n/2, n/4, ..., 1]
    for(int k = maxSize/2; k >= 1; k = k / 2){
        selectK(k);
        if (verbose == true)
        {
            display();
        }
    }
    // * ------------ end ------------
    clock_t end = clock();
    timeElasped = (double)(end - begin) / (double)CLOCKS_PER_SEC;
}

void Sorting::merge()
{
    timeElasped = 0.0;
    SwapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // * ------------ begin ------------
    ArrayList *tempData = new ArrayList(maxSize);
    for (int i = 0; i < maxSize; ++i)
        tempData->add(i, 0);

    copyArray(Data, tempData, 0, maxSize - 1);

    merge_(tempData, Data, 0, maxSize - 1);

    delete tempData;
    // * ------------ end ------------
    clock_t end = clock();
    timeElasped = (double)(end - begin) / (double)CLOCKS_PER_SEC;
}


void Sorting::bubble_(int n)
{
    // * do bubble for n elements
    for (int i = 0; i < n - 1; ++i)
    {
        // * check condition for swapping
        if (Data->get(i) > Data->get(i + 1))
            swap(i, i + 1);

        loopCounter++;
    }
}

void Sorting::selectK(int k)
{
    // * do insertion for n element with k displacement
    for(int i = 0; i < k; ++i)
        // * do selection sort with k displacement
        for(int j = i; j < maxSize; j = j + k){
            int imin = findMinIndexK(j, k);
            swap(j, imin);
            loopCounter++;
        }
}

int Sorting::findMinIndexK(int iStart, int k)
{
    // * first set min index at first index
    int minIndex = iStart;

    // * scan for index of minimum value 
    for(int i = iStart + k; i < maxSize; i = i + k){
        if(Data->get(i) < Data->get(minIndex)){
            minIndex = i;
        }
    }

    // * return index of minimum value
    return minIndex;
}

void Sorting::copyArray(ArrayList *src, ArrayList *dest, int begin, int end)
{
    for (int i = begin; i <= end; ++i)
        dest->set(i, src->get(i));
}

void Sorting::merge_(ArrayList *Data, ArrayList *result, int begin, int end)
{
    // * check number of Data
    if (end - begin <= 0)return;

    int half = (begin + end) / 2;

    // * continue divide Data
    merge_(Data, result, begin, half);
    merge_(Data, result, half + 1, end);

    // * merge sort
    int i = begin, j = half + 1;
    for (int k = begin; k <= end; ++k)
    {
        if (i > half)
            // * remain only j data, select d[j]
            result->set(k, Data->get(j++));
        else if (j > end)
            // * remain only i data, select d[i]
            result->set(k, Data->get(i++));
        else if (Data->get(i) > Data->get(j))
            // * d[i] > d[j], select d[j]
            result->set(k, Data->get(j++));
        else
            // * d[i] > d[j], select d[j]
            result->set(k, Data->get(i++));

        loopCounter++;
    }
    // * update result to data before return
    copyArray(result, Data, begin, end);
}

void Sorting::quick(bool verbose)
{
    timeElasped = 0.0;
    SwapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // * ------------ begin ------------
    quick_(0, maxSize - 1);
    if (verbose == true)
        {
            display();
        }

    // * ------------ end ------------
    clock_t end = clock();
    timeElasped = (double)(end - begin) / (double)CLOCKS_PER_SEC;
}

void Sorting::quick_(int begin, int end)
{   
    // * check index
    if((end - begin) <= 0) return;

    // * pick pivot index
    int iPivot = pickPivotIndex(begin, end);

    // * swap between index of pivot and last data
    swap(iPivot, end);

    // * parrtition to two data sets
    int i = begin, j = end - 1;
    while(i <= j){
        while(i <= j && Data->get(i) < Data->get(end)) ++i;
        while(i <= j && Data->get(j) >= Data->get(end)) j--;
        if(i < j) swap(i, j);
        loopCounter++;
    }
    // * swap i and end (pivot)
    swap(i, end);

    // * perform quick sort in two Data sets, recursively
    quick_(begin, i - 1);
    quick_(i + 1, end);
}

int Sorting::pickPivotIndex(int begin, int end)
{
    // * calculate middle position
    int mid = (begin + end) / 2;

    // * re-assign variables (easy to call), like  a, b and c
    int a = Data->get(begin), b = Data->get(mid), c = Data->get(end);
    // * check for middle conditions
    if((a >= b && b >= c) || (a <= b && b <= c))
        return mid;
    else if((b >= c && c >= a) || (b <= c && c <= a))
        return end;
    else if((c >= a && a >= b) || (c <= a && a <= b))
        return begin;

    // * un - reachable code, just for warning avoidance
    return mid;
}