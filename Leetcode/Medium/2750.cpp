#include "headers.h"

class Solution
{
public:
    int numberOfGoodSubarraySplits(vector<int> &v)
    {
        long long ans = 1, i = 0, n = v.size(), mod = 1e9 + 7, z = 0;
        while(i < n && v[i] != 1)
            i++;

        if  (i == n)
            return 0;
        for (i++; i < n; i++) {
            if (v[i] == 0)
                z++;
            else {
                ans = (ans * (z + 1)) % mod;
                z = 0;
            }
        }
        return ans % mod;
    }
};