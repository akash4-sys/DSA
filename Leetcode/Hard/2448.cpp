#include "../../headers.h"

// Trinary Search
// Time Complexity - O(NlogN)
// Space Compelxity - O(1)

class Solution
{
    long long convert(vector<int> &v, vector<int> &c, int val)
    {
        long long res = 0;
        for (int i = 0; i < v.size(); i++)
            res += (1LL * abs(v[i] - val) * c[i]);
        return res;
    }

public:
    long long minCost(vector<int> &v, vector<int> &c)
    {
        long long ans = convert(v, c, 1), l = 1, r = 1e6;
        while (l < r)
        {
            long long mid = (l + r) / 2;
            long long x = convert(v, c, mid), y = convert(v, c, mid + 1);
            ans = min(x, y);
            if (x < y)
                r = mid;
            else
                l = mid + 1;
        }
        return ans;
    }
};



// Pure Weighted Median
// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
    long long convert(vector<vector<long long>> &v, int val)
    {
        long long res = 0;
        for (int i = 0; i < v.size(); i++)
            res += (1LL * abs(v[i][0] - val) * v[i][1]);
        return res;
    }

public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        long long n = nums.size(), sum = 0;
        vector<long long> pf;
        vector v(n, vector<long long>(2));

        for (int i = 0; i < n; i++)
            v[i] = {nums[i], cost[i]};

        sort(v.begin(), v.end());
        for (auto a : v)
            pf.push_back(sum += a[1]);

        long long k = lower_bound(pf.begin(), pf.end(), sum / 2) - pf.begin();
        long long ans = convert(v, v[k][0]);
        if (pf[k] == sum / 2 && k + 1 < n)
            return min(ans, convert(v, v[k + 1][0]));
        return ans;
    }
};