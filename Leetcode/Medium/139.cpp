#include "../../headers.h"

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> ump(begin(wordDict), end(wordDict));
        int n = s.length();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < i && !dp[i]; ++j)
                dp[i] = dp[j] && ump.count(s.substr(j, i - j));
        return dp[n];
    }
};