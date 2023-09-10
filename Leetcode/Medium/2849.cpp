#include "../../headers.h"

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int x = abs(sx - fx), y = abs(sy - fy);
        if (x == 0 && y == 0 && t == 1)
            return 0;
        return (min(x, y) + abs(x - y)) <= t;
    }
};