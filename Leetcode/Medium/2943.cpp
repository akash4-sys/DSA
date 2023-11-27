#include "../../headers.h"

class Solution
{
    int getMaxGap(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int cnt = 2, res = 2;
        for (int i = 1; i < v.size(); ++i)
        {
            cnt = (v[i - 1] + 1 == v[i]) ? cnt + 1 : 2;
            res = max(res, cnt);
        }
        return res;
    }

public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        int gap = min(getMaxGap(hBars), getMaxGap(vBars));
        return gap * gap;
    }
};