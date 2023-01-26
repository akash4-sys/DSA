#include "../../headers.h"

class Solution 
{
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) 
    {
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {ef[i], sp[i]};
        sort(v.rbegin(), v.rend());

        long ans = 0, sum = 0, mod = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto [e, s]: v)
        {
            pq.push(s);
            sum += s;
            if (pq.size() > k)
                sum -= pq.top(), pq.pop();
            ans = max(ans, sum * e);
        }
        return ans % mod;
    }
};