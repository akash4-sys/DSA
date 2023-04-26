#include "../../headers.h"

// Same logic as lcs just return line is different

class Solution
{
    int lcs(vector<vector<int>> &dp, string &s, string &r, int i, int j)
    {
        if (i == s.size() || j == s.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == r[j])
            return dp[i][j] = lcs(dp, s, r, i + 1, j + 1) + 1;
        return dp[i][j] = max(lcs(dp, s, r, i + 1, j), lcs(dp, s, r, i, j + 1));
    }

public:
    int minInsertions(string s)
    {
        vector dp(s.size(), vector<int>(s.size(), -1));
        string r = s;
        reverse(r.begin(), r.end());
        return s.size() - lcs(dp, s, r, 0, 0);
    }
};



class Solution
{
public:
    int minInsertions(string s)
    {
        string r = s;
        reverse(r.begin(), r.end());
        vector<int> dp(s.size() + 1, 0);
        for (int i = 1; i <= s.size(); i++)
        {
            int prev = 0;
            for (int j = 1; j <= s.size(); j++)
            {
                int curr = dp[j];
                dp[j] = max({dp[j], dp[j - 1], prev + (s[i - 1] == r[j - 1])});
                prev = curr;
            }
        }
        return s.size() - dp[s.size()];
    }
};