#include "../../headers.h"

// Time Complexity - O(N^2 * Log(N))
// Here you can solve this problem without j state it just slightly improves performance

class Solution
{
    map<pair<int, int>, int> mp;
    int rec(vector<int> &a, vector<int> &b, int prev, int i, int j)
    {
        if (i == a.size())
            return 0;
        if (mp.count({prev, i}))
            return mp[{prev, i}];

        int res = INT_MAX;
        if (prev < a[i])
            res = rec(a, b, a[i], i + 1, j);

        int k = lower_bound(b.begin() + j, b.end(), prev + 1) - b.begin();
        if (k == b.size())
            return mp[{prev, i}] = res;
        int x = rec(a, b, b[k], i + 1, k + 1);
        return mp[{prev, i}] = min(res, x + (x != INT_MAX));
    }

public:
    int makeArrayIncreasing(vector<int> &a, vector<int> &b)
    {
        sort(b.begin(), b.end());
        b.resize(distance(b.begin(), unique(b.begin(), b.end())));
        int ans = rec(a, b, -1, 0, 0);
        return ans != INT_MAX ? ans : -1;
    }
};