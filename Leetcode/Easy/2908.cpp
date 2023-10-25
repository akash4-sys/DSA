#include "../../headers.h"

class Solution
{
public:
    int minimumSum(vector<int> &v)
    {
        int ans = INT_MAX, n = v.size(), mn = v[0];
        vector<int> sf(n, INT_MAX);
        for (int i = n - 1; i >= 0; i--)
            sf[i] = min(sf[i + 1 < n ? i + 1 : i], v[i]);
        
        for (int i = 1; i < n - 1; i++)
        {
            if (mn < v[i] && v[i] > sf[i + 1])
                ans = min(ans, mn + sf[i + 1] + v[i]);
            mn = min(mn, v[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};