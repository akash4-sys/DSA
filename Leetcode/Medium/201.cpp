#include "../../headers.h"

// Time complexity - O(32)

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans = 0;
        for (long long x = 1LL << 31; x; x >>= 1)
        {
            if ((left & x) != (right & x))
                return ans;
            ans |= (left & x);
        }
        return ans;
    }
};


// Time complexity - O(N)  // where N is r - l

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        if (!left || !right || (int)log2(left) != (int)log2(right))
            return 0;
        int ans = left;
        for (int i = left + 1; i <= right; i++)
            ans &= i;
        return ans;
    }
};