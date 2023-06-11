#include "../../headers.h"

class Solution
{
public:
    int maxValue(int n, int i, int sum)
    {
        sum -= n;
        int l = 1, r = sum;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            int a = max(mid - i, 0), b = max(mid - n + i + 1, 0);
            long csum = long(mid + a) * (mid - a + 1) / 2;
            csum += (long(mid + b) * (mid - b + 1) / 2) - mid;
            if (sum >= csum)
                l = mid;
            else
                r = mid - 1;
        }
        return l + 1;
    }
};