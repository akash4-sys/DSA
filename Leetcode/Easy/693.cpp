#include "../../headers.h"

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        // limit when n is INT_MAX can't do + 1
        // return !((n ^= (n >> 1)) & (n + 1));
        return !((n ^= (n >> 2)) & (n - 1));
    }
};

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int last = -1;
        for (;n > 0; n >>= 1)
        {
            if ((n & 1) == last)
                return false;
            last = n & 1;
        }
        return true;
    }
};


class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int last = -1;
        for (;n > 0; n /= 2)
        {
            if (n % 2 == last)
                return false;
            last = n % 2;
        }
        return true;
    }
};