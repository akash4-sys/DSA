#include "../../headers.h"

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        long long p = -1, a = 0, b = 0, cnt = 0;
        for (int x : hBars)
        {
            if (p + 1 != x)
                cnt = 0;
            p = x;
            a = max(a, ++cnt);
        }
        p = -1, cnt = 0;
        for (int x : vBars)
        {
            if (p + 1 != x)
                cnt = 0;
            p = x;
            b = max(b, ++cnt);
        }
        
        long long x = min(a, b), ans = (x + 1) * (x + 1);
        return max(ans, 1LL);
    }
};