#if !defined(_ARRAYLIST_H)
#define _ARRAYLIST_H

// * #define DEFAULT_MAX_SIZE 5

class ArrayList
{
    private: // * data
        int *L; // ! List element
        int maxSize; // * maximum element
        int curSize; // * current number element   
    
    public: // * method
        ArrayList(int maxSize); // ! contructor *important (1)*
        ~ArrayList(); // ! destructor
        // * basic method
        int size(); 
        int indexOf(int e);
        int get(int i);
        void set(int i, int e);
        int remove(int i);
        void add(int i,int e);

        void clear();
        int max();
        int min();

        int oddCount();
        int evenCount();
        float sum();
        float mean();
        void sort();

        void swap(int &a, int &b);

        void appendRandom(int round);

        // * addition method
        void display();

};

#endif // _ARRAYLIST_H