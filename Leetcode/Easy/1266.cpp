#include "../../headers.h"

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &v)
    {
        int ans = 0;
        for (int i = 1; i < v.size(); i++)
            ans += max(abs(v[i][0] - v[i - 1][0]), abs(v[i][1] - v[i - 1][1]));
        return ans;
    }
};