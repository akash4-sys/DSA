#include "../../headers.h"

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int ans = 0, l = 0, m = 0;
        unordered_map<int, int> ump;
        for(int n: nums)
            ump[n]++, m = max(m, n);
        
        vector<int> dp(m + 1, 0);
        for(auto x: ump)
            dp[x.first] = x.first * x.second;

        for(int n: dp)
        {
            int curr = max(ans, l + n);
            l = ans;
            ans = curr;
        }
        return ans;
    }
};