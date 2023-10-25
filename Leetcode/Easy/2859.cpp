#include "../../headers.h"

class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &v, int k)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            if (__builtin_popcount(i) == k)
                ans += v[i];
        return ans;
    }
};