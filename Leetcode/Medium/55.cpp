#include "../../headers.h"

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > maxi)
                return false;
            maxi = max(maxi, nums[i] + i);
        }
        return true;
    }
};



// Tabulation
class Solution 
{
public:
    bool canJump(vector<int>& v)
    {
        vector<int> dp(v.size(), 0);
        dp[v.size() - 1] = 1;

        for (int i = v.size() - 2; i >= 0; i--)
            for (int j = i + 1; j <= min(i + v[i], (int)v.size() - 1); j++)
                if (dp[j])
                {
                    dp[i] = 1;
                    break;
                }
        return dp[0];
    }
};



// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution 
{
    bool jump(vector<int>& v, int i, vector<int> &dp)
    {
        if (i >= v.size() - 1)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        for (int j = i + 1; j <= i + v[i]; j++)
            if(jump(v, j, dp))
                return dp[j] = 1;
        return dp[i] = 0;
    }
    
public:
    bool canJump(vector<int>& v)
    {
        vector<int> dp(v.size() + 1, -1);
        return jump(v, 0, dp);
    }
};