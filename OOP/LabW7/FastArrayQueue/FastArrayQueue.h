#if !defined(_FASTARRAYQUEUE_H)
#define _FASTARRAYQUEUE_H

#define DEFAULT_MAX_SIZE 9

class FastArrayQueue
{
    private:
        int *L;
        int curSize;
        int maxSize;
        int in;
        int out;

        
    public:
        FastArrayQueue(int maxSize = DEFAULT_MAX_SIZE); // * constructor
        ~FastArrayQueue();

        // * method
        void enQueue(int e);
        int deQueue();
        int front();
        int rear();

        void display();

        void append(int e){ enQueue(e); };
        int remove(){ return deQueue(); };
        int head(){ return front(); };
        int back(){ return rear(); };

        void enQueueFloat(float e); // * normal
        float deQueueFloat();

        void enQueueLong(long e); // * hard
        long deQueueLong();

        void enQueueCString(char *s);
        char *deQueueCString();

};

#endif // _FASTARRAYQUEUE_H
