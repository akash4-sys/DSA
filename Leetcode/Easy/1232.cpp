#include "../../headers.h"

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &v)
    {
        double dx = v[1][0] - v[0][0], dy = v[1][1] - v[0][1];
        for (int i = 2; i < v.size(); i++)
            if (dy * (v[i][0] - v[i - 1][0]) != dx * (v[i][1] - v[i - 1][1]))
                return 0;
        return 1;
    }
};