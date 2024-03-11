#include "../../headers.h"

class Solution
{
public:
    int minOperations(vector<int> &v, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int a : v)
            pq.push(a);
        
        int ans = 0;
        while (pq.size() >= 2)
        {
            if (pq.top() >= k)
                return ans;
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(min(x, y) * 2LL + max(x, y));
            ans++;
        }
        return ans;
    }
};