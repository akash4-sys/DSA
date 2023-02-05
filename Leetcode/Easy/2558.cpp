#include "headers.h"

class Solution
{
public:
    long long pickGifts(vector<int> &v, int k)
    {
        priority_queue<int> pq;
        for (int n : v)
            pq.push(n);

        while (k--)
        {
            int x = pq.top();
            pq.pop();
            x = sqrt(x);
            pq.push(x);
        }

        long long sum = 0;
        while (pq.size())
            sum += pq.top(), pq.pop();
        return sum;
    }
};