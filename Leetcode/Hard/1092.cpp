#include "../../headers.h"

class Solution
{
    string lcs(string s, string r)
    {
        vector<vector<string>> dp(s.size() + 1, vector<string>(r.size() + 1, ""));
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < r.size(); j++)
            {
                if (s[i] == r[j])
                    dp[i + 1][j + 1] = dp[i][j] + s[i];
                else
                    dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ? dp[i + 1][j] : dp[i][j + 1];
            }
        return dp[s.size()][r.size()];
    }

public:
    string shortestCommonSupersequence(string s, string r)
    {
        string LCS = lcs(s, r), ans = "";
        int i = 0, j = 0;
        for (char c : LCS)
        {
            while (s[i] != c)
                ans += s[i++];
            while (r[j] != c)
                ans += r[j++];
            ans += c;
            i++, j++;
        }
        return ans + s.substr(i) + r.substr(j);
    }
};