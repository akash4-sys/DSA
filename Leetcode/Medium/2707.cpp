#include "headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int minExtraChar(string s, vector<string> &v)
    {
        unordered_set st(v.begin(), v.end());
        vector<int> dp(s.size() + 1, 0);
        for (int i = s.size() - 1; i >= 0; i--)
        {
            string r = "";
            int res = INT_MAX;
            for (int j = i; j < s.size(); j++)
            {
                r += s[j];
                int x = st.find(r) == st.end() ? r.size() : 0;
                res = min(res, dp[j + 1] + x);
            }
            dp[i] = res;
        }
        return dp[0];
    }
};


class Solution
{
    unordered_set<string> st;
    int rec(string &s, vector<int> &dp, int i)
    {
        if (i == s.size())
            return 0;

        if (dp[i] != INT_MAX)
            return dp[i];

        string r = "";
        for (int j = i; j < s.size(); j++)
        {
            r += s[j];
            int x = st.find(r) == st.end() ? r.size() : 0;
            dp[i] = min(dp[i], rec(s, dp, j + 1) + x);
        }
        return dp[i];
    }

public:
    int minExtraChar(string s, vector<string> &v)
    {
        st = unordered_set(v.begin(), v.end());
        vector<int> dp(s.size(), INT_MAX);
        return rec(s, dp, 0);
    }
};