#include "../../headers.h"

class Solution
{
public:
    int findKOr(vector<int> &v, int k)
    {
        int ans = 0, bit[32] = {0};
        for (int x : v)
            for (int i = 0; i < 32; i++)
                bit[i] += !!(x & (1 << i));
        
        for (int i = 0; i < 32; i++)
            if (bit[i] >= k)
                ans |= (1 << i);
        return ans;
    }
};