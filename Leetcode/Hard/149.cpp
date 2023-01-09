#include "../../headers.h"

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ans = 0;
        for (auto &p : points)
        {
            unordered_map<double, int> ump;
            int dup = 0;
            for (auto &q : points)
            {
                int dx = q[0] - p[0], dy = q[1] - p[1];
                if (!dx && !dy)
                {
                    dup++;
                    continue;
                }
                double slope = dx ? (dy * 1.0) / dx : INT_MAX;
                ump[slope]++;
            }

            if (ump.size())
                for (auto &[slp, c] : ump)
                    ans = max(ans, c + dup);
            else
                ans = dup;
        }
        return ans;
    }
};