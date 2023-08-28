#pragma once

#include <string>
#include <vector>

using namespace std;

vector<int> lcs_index(string s, string r)
{
    vector<int> dp(r.size() + 1, 0), idx(r.size());
    for (int i = 1; i <= s.size(); i++)
    {
        int prev = 0;
        for (int j = 1; j <= r.size(); j++)
        {
            int curr = dp[j];
            dp[j] = max({dp[j], dp[j - 1], prev + (s[i - 1] == r[j - 1])});
            if (dp[j] != curr)
                idx[j - 1] = i - 1;
            prev = curr;
        }
    }
    return idx;
}


// returns longest common subsequence
string lcs(string s, string r)
{
    vector dp(s.size() + 1, vector<string>(r.size() + 1, ""));
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