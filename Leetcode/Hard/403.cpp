#include "../../headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
public:
    bool canCross(vector<int> &v)
    {
        vector dp(v.size(), vector<bool>(v.size(), 0));
        dp[0][1] = 1;

        for (int i = 1; i < v.size(); i++)
            for (int j = 0; j < i; j++)
            {
                int d = v[i] - v[j];
                if (d < v.size() && dp[j][d])
                {
                    if (i == v.size() - 1)
                        return 1;
                    dp[i][d] = 1;
                    dp[i][d - 1] = d - 1 >= 0;
                    dp[i][d + 1] = d + 1 >= 0;
                }
            }
        return 0;
    }
};


// Time Complexity - O(3*NLogN)
// Space Complexity - O(N^2)

class Solution
{
    int dp[2001][2001];
    bool rec(vector<int> &v, int i, int k)
    {
        if (i == v.size() - 1)
            return 1;
        if (dp[i][k] != -1)
            return dp[i][k];
        
        bool res = 0;
        for (int a : {k - 1, k, k + 1})
        {
            int j = lower_bound(v.begin() + i + 1, v.end(), v[i] + a) - v.begin();
            if (j < v.size() && v[j] - v[i] == a)
                res |= rec(v, j, a);
        }
        return dp[i][k] = res;
    }

public:
    bool canCross(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, 0, 0);
    }
};