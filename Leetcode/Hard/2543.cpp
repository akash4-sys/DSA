#include "../../headers.h"

class Solution
{
public:
    bool isReachable(int x, int y)
    {
        if (x == 1 && y == 1)
            return 1;
        if (y > x)
            return isReachable(x, y - x);
        if (x > y)
            return isReachable(x - y, y);
        if (x % 2 == 0)
            return isReachable(x / 2, y);
        if (y % 2 == 0)
            return isReachable(x, y / 2);
        return 0;
    }
};

// @lc app=leetcode id=2543 lang=cpp