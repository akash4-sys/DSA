#include "../../headers.h"

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &v)
    {
        int area = 0, d = 0;
        for (auto r : v)
        {
            int t = (r[0] * r[0]) + (r[1] * r[1]);
            if (t > d)
                area = r[0] * r[1], d = t;
            else if (t == d)
                area = max(area, r[0] * r[1]);
        }
        return area;
    }
};