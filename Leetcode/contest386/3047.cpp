#include "../../headers.h"

class Solution
{
    long long area(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
    {
        long long x5 = max(x1, x3);
        long long y5 = max(y1, y3);
        long long x6 = min(x2, x4);
        long long y6 = min(y2, y4);
        if (x5 > x6 || y5 > y6)
            return 0;

        long long s1 = abs(x5 - x6);
        long long s2 = abs(y6 - y5);
        return min(s1, s2) * min(s1, s2);
    }

public:
    long long largestSquareArea(vector<vector<int>> &b, vector<vector<int>> &t)
    {
        long long ans = 0;
        for (int i = 0; i < b.size(); i++)
            for (int j = i + 1; j < b.size(); j++)
                ans = max(ans, area(b[i][0], b[i][1], t[i][0], t[i][1], b[j][0], b[j][1], t[j][0], t[j][1]));
        return ans;
    }
};