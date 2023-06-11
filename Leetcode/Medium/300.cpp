#include "../../headers.h"

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> v;
        v.push_back(nums[0]);
        for (int n : nums)
        {
            if (n > v.back())
                v.push_back(n);
            else
            {
                int i = lower_bound(v.begin(), v.end(), n) - v.begin();
                v[i] = n;
            }
        }
        return v.size();
    }
};

class Solution
{
public:
    int lengthOfLIS(vector<int> &v)
    {
        int ans = 1, n = v.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (v[i] > v[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
        return ans;
    }
};

class Solution
{
    vector<int> dp;
    int lis(vector<int> &v, int i, int prev)
    {
        if (i == v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
            
        int len = 0;
        for (int j = i; j < v.size(); j++)
            if (v[j] > prev)
                len = max(len, lis(v, j + 1, v[j]) + 1);
        return dp[i] = len;
    }

public:
    int lengthOfLIS(vector<int> &v)
    {
        dp = vector<int>(v.size(), -1);
        return lis(v, 0, INT_MIN);
    }
};