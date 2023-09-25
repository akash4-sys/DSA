#include "../../headers.h"

class Solution
{
    int dirs[9][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 0}};

public:
    vector<int> gridIllumination(int n, vector<vector<int>> &v, vector<vector<int>> &qrs)
    {
        map<pair<int, int>, int> lamps;
        unordered_map<int, int> row, col, ld, dd;

        auto switchBulb = [&](int i, int j, int on) {
            row[i] += on;
            col[j] += on;
            ld[i + j] += on;
            dd[i - j] += on;
            lamps[{i, j}] = on > 0;
        };

        for (auto &r : v)
            if (!lamps.count({r[0], r[1]}))
                switchBulb(r[0], r[1], 1);

        vector<int> ans;
        for (auto q : qrs)
        {
            int i = q[0], j = q[1];
            ans.push_back(row[i] || col[j] || ld[i + j] || dd[i - j]);
            for (auto [x, y] : dirs)
                if (lamps.count({i + x, j + y}) && lamps[{i + x, j + y}])
                    switchBulb(i + x, j + y, -1);
        }
        return ans;
    }
};

// @lc app=leetcode id=1001 lang=cpp