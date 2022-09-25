#include "../../headers.h"

class MyCircularQueue
{
    vector<int> queue;
    int k, front, csize;
public:
    MyCircularQueue(int sz): queue(sz), k(sz), csize(0), front(0) {}

    bool enQueue(int v)
    {
        if(isFull())
            return false;
        queue[(front + csize) % k] = v;
        csize++;
        return true;
    }

    bool deQueue()
    {
        if(isEmpty())
            return false;
        front = (front + 1) % k;
        csize--;
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : queue[front];
    }

    int Rear()
    {
        return isEmpty() ? -1 : queue[(front + csize - 1) % k];
    }

    bool isEmpty()
    {
        return !csize;
    }

    bool isFull()
    {
        return csize == k;
    }
};