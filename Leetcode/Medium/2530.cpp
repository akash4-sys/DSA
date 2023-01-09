#include "headers.h"

class Solution
{
public:
    long long maxKelements(vector<int> &v, int k)
    {
        long long ans = 0;
        priority_queue<int> pq;
        for (int n : v)
            pq.push(n);
        
        while (k--)
        {
            int x = pq.top();
            pq.pop();
            ans += (long)x;
            x = ceil(x / 3.0);
            pq.push(x);
        }
        return ans;
    }
};