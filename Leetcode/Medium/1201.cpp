#include "../../headers.h"

#define l long
class Solution
{
public:
    int nthUglyNumber(int n, int x, int y, int z)
    {
        int lo = 1, hi = 2e9;
        l a = (l)x, b = (l)y, c = (l)z, ab = lcm(a, b), bc = lcm(b, c), ac = lcm(a, c), abc = lcm(ab, c);
        while (lo < hi)
        {
            int mid = lo + ((hi - lo) / 2);
            int cnt = (mid / a) + (mid / b) + (mid / c) - (mid / ab) - (mid / ac) - (mid / bc) + (mid / abc);
            if (cnt < n)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};