#include "../../headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
    int dp[201][20001];
    bool rec(vector<int> &v, int i, int sum)
    {
        if (!sum)
            return 1;
        if (i == v.size() || sum < 0)
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] = rec(v, i + 1, sum - v[i]) || rec(v, i + 1, sum);
    }

public:
    bool canPartition(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(v.begin(), v.end(), 0);
        return sum % 2 ? 0 : rec(v, 0, sum / 2);
    }
};