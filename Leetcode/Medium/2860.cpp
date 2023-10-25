#include "../../headers.h"

class Solution
{
public:
    int countWays(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int ans = v[0] != 0, n = v.size();
        v.push_back(INT_MAX);
        for (int i = 0; i < n; i++)
            ans += (i + 1 > v[i] && i + 1 < v[i + 1]);
        return ans;
    }
};