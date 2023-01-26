#include "headers.h"

class Solution
{
public:
    long long maxScore(vector<int> &a, vector<int> &b, int k)
    {
        vector<pair<int, int>> v(a.size());
        for (int i = 0; i < a.size(); i++)
            v[i] = {b[i], a[i]};
        sort(v.rbegin(), v.rend());

        long long ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto [y, x]: v)
        {
            pq.push(x);
            sum += x;
            if (pq.size() > k)
                sum -= pq.top(), pq.pop();
            ans = max(ans, sum * y);
        }
        return ans;
    }
};