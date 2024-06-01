#include "../../headers.h"

class Solution
{
public:
    int minRectanglesToCoverPoints(vector<vector<int>> &v, int w)
    {
        int ans = 0, j = 0;
        sort(v.begin(), v.end());
        v.push_back({v.back()[0] + w + 1, 0});
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i][0] - v[j][0] > w)
            {
                ans++;
                j = i;
            }
        }
        return ans;
    }
};