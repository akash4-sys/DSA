#include "../../headers.h"

class Solution
{
public:
    int stoneGameII(vector<int> &v)
    {
        vector<vector<int>> dp(v.size() + 1, vector<int>(v.size() + 1, INT_MIN));
        vector<int> suffixSum(v.size() + 1);
        dp[v.size()][v.size()] = 0;

        int sum = 0;
        for(int i = v.size() - 1; i >= 0; i--)
            sum += v[i], suffixSum[i] = sum, dp[v.size()][i] = 0;

        for(int i = v.size() - 1; i >= 0; i--)
            for(int m = 1; m <= v.size(); m++)
                for(int x = 1; x <= 2*m && i + x <= v.size(); x++)
                    dp[i][m] = max(dp[i][m], (suffixSum[i] - suffixSum[i + x]) - dp[i + x][max(x, m)]);
        return (sum + dp[0][1]) / 2;
    }
};


class Solution
{
    int recurse(vector<vector<int>> &dp, vector<int> &v, int m, int i, int t)
    {
        if(i >= v.size())
            return 0;
        if(dp[i][m] != -1)
            return dp[i][m];
    
        int ans = INT_MIN, sum = 0;
        for(int x = 0; x < 2 * m && i + x < v.size(); x++)
            sum += v[i + x], ans = max(ans, sum - recurse(dp, v, max(x + 1, m), i + x + 1, 1));
            
        return dp[i][m] = ans;
    }

public:
    int stoneGameII(vector<int> &v)
    {
        vector<vector<int>> dp(v.size() + 1, vector<int>(v.size() + 1, -1));
        int sum = accumulate(v.begin(), v.end(), 0);
        return (sum + recurse(dp, v, 1, 0, 0)) / 2;
    }
};


class Solution
{
    int recurse(vector<vector<vector<int>>> &dp, vector<int> &v, int m, int i, int t)
    {
        if(i >= v.size())
            return 0;
        if(dp[i][m][t] != -1)
            return dp[i][m][t];
        if(!t)
        {
            int ans = 0, sum = 0;
            for(int x = 0; x < 2 * m && i + x < v.size(); x++)
                sum += v[i + x], ans = max(ans, sum + recurse(dp, v, max(x + 1, m), i + x + 1, 1));
            return dp[i][m][t] = ans;
        }
        int ans = INT_MAX;
        for(int x = 0; x < 2 * m && i + x < v.size(); x++)
            ans = min(ans, recurse(dp, v, max(x + 1, m), i + x + 1, 0));
        return dp[i][m][t] = ans;
    }

public:
    int stoneGameII(vector<int> &v)
    {
        vector<vector<vector<int>>> dp(v.size() + 1, vector<vector<int>>(v.size() + 1, vector<int>(2, -1)));
        return recurse(dp, v, 1, 0, 0);
    }
};


class Solution
{
    int recurse(vector<int> &v, int m, int i, int t)
    {
        if(i >= v.size())
            return 0;
        if(!t)
        {
            int ans = 0, sum = 0;
            for(int x = 0; x < 2 * m && i + x < v.size(); x++)
                sum += v[i + x], ans = max(ans, sum + recurse(v, max(x + 1, m), i + x + 1, 1));
            return ans;
        }
        int ans = INT_MAX;
        for(int x = 0; x < 2 * m && i + x < v.size(); x++)
            ans = min(ans, recurse(v, max(x + 1, m), i + x + 1, 0));
        return ans;
    }

public:
    int stoneGameII(vector<int> &v)
    {
        return recurse(v, 1, 0, 0);
    }
};