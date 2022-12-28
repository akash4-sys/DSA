#include "../../headers.h"

class Solution
{
public:
    int minStoneSum(vector<int> &v, int k)
    {
        int ans = 0;
        priority_queue<int> pq;
        for (auto n : v)
            pq.push(n), ans += n;
        
        while (k--)
        {
            int x = pq.top();
            pq.pop();
            ans -= x / 2;
            x = ceil(x / 2.0);
            pq.push(x);
        }
        return ans;
    }
};