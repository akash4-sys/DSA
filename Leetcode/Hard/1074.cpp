#include "../../headers.h"

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &v, int t)
    {
        int n = v.size(), m = v[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                v[i][j] += v[i][j - 1];
        
        for (int k = 0; k < m; k++)
            for (int j = k; j < m; j++)
            {
                unordered_map<int, int> mp = {{0, 1}};
                for (int i = 0, sum = 0; i < n; i++)
                {
                    sum += v[i][j] - (k ? v[i][k - 1] : 0);
                    ans += mp[sum - t];
                    mp[sum]++;
                }
            }
        return ans;
    }
};