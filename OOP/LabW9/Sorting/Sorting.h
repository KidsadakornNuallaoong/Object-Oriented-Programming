#if !defined(_SORTING_H)
#define _SORTING_H

#define DEFAULT_SIZE 16

#include "../ArrayList/arrayList.h"

class Sorting 
{
private:
    // * Data list
    ArrayList *Data; // * Data for Sorting
    ArrayList *temp; // * backup Data
    int maxSize;     // * number of Data

    double timeElasped; // * measure by time
    unsigned long loopCounter; // * measure by looping
    unsigned long SwapCounter;  // * measure by swap
    
public:
    Sorting(int maxSize = DEFAULT_SIZE); // ! constructor
    ~Sorting();                          // ! Destructor

    void display(); // * display current all Data
    void displayTimeElasped(); // * display time elasped
    void displayLoopCounter(); // * display loop
    void diaplaySwapCounter(); // * display swap counter

    void random();
    void backUp(); // * Data -> temp
    void restore(); // * temp -> Data

    // ! Sorting alg.
    // * selection Sort
    void selection(bool verbose = false); // * verbose = true --> display

    // * insertion Sort
    void insertion(bool verbose = false);
    
    // * bubble Sort
    void bubble(bool verbose = false);

    // * NEW
    // * shell Sort
    void shell(bool verbose = false);

    void merge();

    void quick(bool verbose = false);


    void reRandom(){random();};

private:
    
    int findMaxIndex(int n);
    void swap(int i, int j);

    void insert(int n);

    void bubble_(int n);

    // * NEW
    void selectK(int k);
    int findMinIndexK(int iStart, int k);

    void copyArray(ArrayList *src, ArrayList *dest, int begin, int end);
    void merge_(ArrayList *Data, ArrayList *result, int begin, int end);

    void quick_(int begin, int end);
    int pickPivotIndex(int begin, int end);


};

#endif // _SORTING_H