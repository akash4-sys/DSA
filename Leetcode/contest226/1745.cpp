#include "../../headers.h"

class Solution
{
public:
    bool checkPartitioning(string &s)
    {
        int n = s.size();
        vector dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);
        
        for (int i = 1; i < n - 1; i++)
            for (int j = i; j < n - 1 && dp[0][i - 1]; j++)
                if (dp[i][j] && dp[j + 1][n - 1])
                    return 1;
        return 0;
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
    int dp[2001];
    bool isPalindrome(string &s, int i, int j)
    {
        if (i > j)
            return 0;
        for (; i <= j && s[i] == s[j]; i++, j--);
        return i > j;
    }

    int rec(string &s, int i)
    {
        if (dp[i] != -1)
            return dp[i];
        for (int j = i; j < s.size(); j++)
            if (isPalindrome(s, i, j) && isPalindrome(s, j + 1, s.size() - 1))
                return dp[j] = 1;
        return dp[i] = 0;
    }

public:
    bool checkPartitioning(string &s)
    {
        int res = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < s.size(); i++)
            if (isPalindrome(s, 0, i))
                res |= rec(s, i + 1);
        return res;
    }
};