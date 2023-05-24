#include "headers.h"

class Solution
{
public:
    int matrixSum(vector<vector<int>> &v)
    {
        int ans = 0;
        for (auto &r : v)
            sort(r.begin(), r.end());
        for (int j = v[0].size() - 1; j >= 0; --j)
        {
            int x = 0;
            for (int i = 0; i < v.size(); ++i)
                x = max(x, v[i][j]);
            ans += x;
        }
        return ans;
    }
};