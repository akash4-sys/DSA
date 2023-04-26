#include "../../headers.h"

class Solution
{
public:
    int lastStoneWeight(vector<int>& v)
    {
        priority_queue<int> pq(v.begin(), v.end());
        while (!pq.empty())
        {
            if (pq.size() == 1)
                return pq.top();
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            x -= y;
            if (x)
                pq.push(x);
        }
        return 0;
    }
};