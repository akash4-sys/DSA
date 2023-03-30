#include "../../headers.h"

class Solution
{
public:
    int beautifulSubsets(vector<int> &v, int k, int i = 0, int mask = 0)
    {
        if (i == v.size())
            return mask > 0;
        bool flag = 1;
        for (int j = 0; j < i && flag; j++)
            flag = !((1 << j) & mask) || abs(v[j] - v[i]) != k;
        return beautifulSubsets(v, k, i + 1, mask) + (flag ? beautifulSubsets(v, k, i + 1, mask | (1 << i)) : 0);
    }
};