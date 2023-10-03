#include "../headers.h"

#define ll long long

class Solution
{
    int subarrSum(vector<int> &v, int t)
    {
        ll sum = 0, res = INT_MAX;
        for (ll l = 0, r = 0; r < v.size(); r++)
        {
            sum += v[r];
            while (sum > t)
                sum -= v[l++];
            if (sum == t)
                res = min(res, r - l + 1);
        }
        return res == INT_MAX ? -1 : res;
    }

public:
    int minSizeSubarray(vector<int> &v, int t)
    {
        ll sum = accumulate(v.begin(), v.end(), 0LL), n = v.size();   
        for (int i = 0; i < n; i++)
            v.push_back(v[i]);
        
        ll r = t % sum, m = t / sum;
        if (!r)
            return m * n;
        ll len = subarrSum(v, r);
        return len == -1 ? -1 : (m * n) + len;
    }
};