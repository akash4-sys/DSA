#include "../../headers.h"

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &v, int k)
    {
        priority_queue<int> pq;
        for (int a : v)
            pq.push(a);
        
        long long ans = 0, dec = 0;
        while (k--)
        {
            long long n = max(pq.top() - dec, 0LL);
            pq.pop();
            ans += n;
            dec++;
        }
        return ans;
    }
};