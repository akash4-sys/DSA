#include "../../headers.h"

class Solution
{
public:
    int numberOfArrays(string s, int k)
    {
        int mod = 1e9 + 7, n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; i++)
        {
            string r = "";
            for (int j = i; j < n && s[i] != '0'; j++)
            {
                r += s[j];
                if (stoll(r) > k)
                    break;
                (dp[j + 1] += dp[i]) %= mod;
            }
        }
        return dp[n];
    }
};


class Solution
{
    int mod = 1e9 + 7;
    int ways(string &s, int k, vector<int> &dp, int i)
    {
        if (i == s.size())
            return 1;
        if (dp[i] != -1)
            return dp[i];

        string r = "";
        dp[i] = 0;
        for (int j = i; j < s.size() && s[i] != '0'; j++)
        {
            r += s[j];
            if (stoll(r) > k)
                break;
            (dp[i] += ways(s, k, dp, j + 1)) %= mod;
        }
        return dp[i];
    }

public:
    int numberOfArrays(string s, int k)
    {
        vector<int> dp(s.size(), -1);
        return ways(s, k, dp, 0);
    }
};