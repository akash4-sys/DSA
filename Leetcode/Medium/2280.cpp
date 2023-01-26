#include "../../headers.h"

class Solution
{
public:
    int minimumLines(vector<vector<int>> &v)
    {
        int ans = v.size() - 1;
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size() - 1; i++)
        {
            int dx1 = v[i + 1][0] - v[i][0], dy1 = v[i + 1][1] - v[i][1];
            int dx2 = v[i][0] - v[i - 1][0], dy2 = v[i][1] - v[i - 1][1];
            ans -= (1LL * dy1 * dx2 == 1LL * dy2 * dx1);
        }
        return ans;
    }
};