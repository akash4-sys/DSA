#include "../../headers.h"

class Solution
{
public:
    int combinationSum4(vector<int> &v, int target)
    {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = *min_element(v.begin(), v.end()); t <= target; t++)
            for (int n : v)
                dp[t] += t >= n ? dp[t - n] : 0;
        return dp[target];
    }
};