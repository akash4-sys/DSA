#include "headers.h"

class Solution
{
public:
    long long dividePlayers(vector<int> &v)
    {
        sort(v.begin(), v.end());
        long ans = (long)v[0] * v.back(), sum = v[0] + v.back();
        for(int l = 1, r = v.size() - 2; l < r; l++, r--)
        {
            if(v[l] + v[r] != sum)
                return -1;
            ans += (long)v[l] * v[r];
        }
        return ans;
    }
};