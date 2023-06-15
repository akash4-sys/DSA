#include "../../headers.h"

class Solution
{
    int dp[1 << 16], sum = 0;
    int rec(vector<int> &v, int mask)
    {
        if (dp[mask] != -2)
            return dp[mask];
        if (!mask)
            return 0;

        for (int i = 0; i < v.size(); i++)
            if(mask & (1 << i))
            {
                int rem = rec(v, mask ^ (1 << i));
                if (rem != -1 && rem + v[i] <= sum)
                    return dp[mask] = (rem + v[i]) % sum;
            }
        return dp[mask] = -1;
    }

public:
    bool canPartitionKSubsets(vector<int> &v, int k)
    {
        int totsum = accumulate(v.begin(), v.end(), 0), n = v.size();
        sum = totsum / k;
        if (totsum % k)
            return 0;

        fill(dp, dp + (1 << 16), -2);
        return rec(v, (1 << n) - 1) == 0;
    }
};




class Solution
{
    bool rec(vector<int> &v, int target, int k, int mask, int sum, int it)
    {
        if (k == 1)
            return 1;
        if (sum == target)
            return rec(v, target, k - 1, mask, 0, 0);
        
        for (int i = it; i < v.size(); i++)
            if (!(mask & (1 << i)) && sum + v[i] <= target)
                if (rec(v, target, k, mask | (1 << i), sum + v[i], i + 1))
                    return 1;
        return 0;
    }

public:
    bool canPartitionKSubsets(vector<int> &v, int k)
    {
        int sum = accumulate(v.begin(), v.end(), 0);
        return sum % k ? 0 : rec(v, sum / k, k, 0, 0, 0);
    }
};