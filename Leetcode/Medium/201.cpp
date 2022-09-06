#include "../../headers.h"

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        if(!left || !right || (int)log2(left) != (int)log2(right))
            return 0;
        int ans = left;
        for(int i = left + 1; i <= right; i++)
            ans &= i;
        return ans;
    }
};