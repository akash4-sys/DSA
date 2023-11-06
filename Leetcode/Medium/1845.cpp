#include "../../headers.h"

class SeatManager
{
    int i = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SeatManager(int n){}

    int reserve()
    {
        int x = pq.empty() ? ++i : pq.top();
        if (!pq.empty())
            pq.pop();
        return x;
    }

    void unreserve(int x) {
        pq.push(x);
    }
};