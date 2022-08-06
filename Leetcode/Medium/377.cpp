#include "../../headers.h"

class Solution
{
public:

    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=0; i<=target; i++)
            for (int n : nums)
                if(i >= n)
                    dp[i] += dp[i - n];

        return dp[target];
    }
};