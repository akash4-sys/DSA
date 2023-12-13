#include "../../headers.h"

class Solution
{
public:
    int arithmeticTriplets(vector<int> &v, int d)
    {
        unordered_map<int, int> mp;
        for (int n : v)
            mp[n]++;
        
        int ans = 0;
        for (int n : v)
            ans += (mp.count(n + d) && mp.count(n + d + d));
        return ans;
    }
};