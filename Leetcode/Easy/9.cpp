#include "../../headers.h"

class Solution
{
public:
     bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int val = 0, xc = x;
        while (x != 0)
        {
            int rem = x % 10;
            x /= 10;
            if (val > INT_MAX / 10 || val == INT_MAX / 10 && rem > 7)
                return false;
            if (val < INT_MIN / 10 || val == INT_MIN / 10 && rem < -8)
                return false;
            val = (val * 10) + rem;
        }
        return (val == xc) ? true : false;
    }
};