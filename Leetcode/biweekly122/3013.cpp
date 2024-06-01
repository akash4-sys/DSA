#include "../../headers.h"

class Solution
{
public:
    long long minimumCost(vector<int>& v, int k, int d)
    {
        int n = v.size();
        long long ans = 0, sum = v[0] + v[1];
        map<int, int> mp;
        priority_queue<int> pq;
        for (int i = 2; i < min(d + 2, n); i++)
            pq.push(-v[i]);

        while (k-- > 2)
            sum += -pq.top(), mp[-pq.top()]++, pq.pop();
        ans = sum;

        for (int i = 3; i <= n - d; i++)
        {
            sum = sum - v[i - 2] + v[i - 1];
            if (mp.count(v[i - 1]))
            {
                sum -= v[i - 1];
                if (--mp[v[i - 1]] == 0)
                    mp.erase(v[i - 1]);
            }
            if (mp.empty() || mp.rbegin()->first >= v[i + d - 1])
                sum += v[i + d - 1], mp[v[i + d - 1]]++;
            ans = min(ans, sum);
        }
        return ans;
    }
};