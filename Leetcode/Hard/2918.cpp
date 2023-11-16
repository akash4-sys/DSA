#include "../../headers.h"

class Solution
{
public:
    long long minSum(vector<int> &a, vector<int> &b)
    {
        long long x = 0, y = 0, az = 0, bz = 0;
        for (int n : a)
            x += n ? n : 1, az += n == 0;
        for (int n : b)
            y += n ? n : 1, bz += n == 0;
        return ((x < y && !az) || (y < x && !bz)) ? -1 : max(x, y);
    }
};