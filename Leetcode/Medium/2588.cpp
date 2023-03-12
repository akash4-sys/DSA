#include "headers.h"

class Solution
{
public:
    long long beautifulSubarrays(vector<int> &v)
    {
        unordered_map<int, int> mp = {{0, 1}};
        long long ans = 0, x = 0;
        for (int n : v)
            x ^= n, ans += mp[x]++;
        return ans;
    }
};