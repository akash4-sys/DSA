#include "../../headers.h"

class Solution
{
    map<pair<int, int>, double> mp;
    
    double rec(int a, int b)
    {
        if (a <= 0)
            return b <= 0 ? 0.5 : 1;
        if (b <= 0)
            return 0;
        if (mp.count({a, b}))
            return mp[{a, b}];
        
        double res = 0;
        for (int i = 1; i <= 4; i++)
            res += 0.25 * rec(a - i, b - 4 + i);
        return mp[{a, b}] = res;
    }

public:
    double soupServings(int n)
    {
        n = ceil(n / 25.0);
        for (int i = 1; i < n; i++)
        if (rec(i, i) > 1 - 1e-5)
            return 1;

        double ans = rec(n, n);
        return ans > 1 - 1e-5 ? 1 : ans;
    }
};