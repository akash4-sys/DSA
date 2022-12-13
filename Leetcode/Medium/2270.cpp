#include "../../headers.h"

class Solution 
{
public:
    int waysToSplitArray(vector<int>& v)
    {
        long long ans = 0, suff = accumulate(v.begin(), v.end(), 0);
        for(long long i = 0, pre = 0; i < v.size() - 1; i++)
        {
            pre += v[i];
            suff -= v[i];
            ans += pre >= suff;
        }
        return ans;
    }
};