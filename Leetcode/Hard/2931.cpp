#include "../../headers.h"

class Solution
{
public:
    long long maxSpending(vector<vector<int>> &v)
    {
        int m = v.size(), n = v[0].size();
        vector<int> idx(m, n - 1);
        long long ans = 0;
        for (int d = 1; d <= m * n; d++)
        {
            long long mx = INT_MAX, j = -1;
            for (int i = 0; i < m; i++)
                if (idx[i] >= 0 && v[i][idx[i]] < mx)
                    mx = v[i][idx[i]], j = i;
            idx[j]--;
            ans += (mx * d);
        }
        return ans;
    }
};