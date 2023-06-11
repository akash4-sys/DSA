#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    bool checkValidString(string s)
    {
        int l = 0, r = 0;
        for (char c : s)
        {
            l += c == '(' ? 1 : -1;
            r += c != ')' ? 1 : -1;
            if (r < 0)
                return 0;
            l = max(l, 0);
        }
        return l == 0;
    }
};

// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

class Solution
{
    int dp[101][101];
    bool dfs(string &s, int i, int open)
    {
        if (i == s.size())
            return !open;
        if (dp[i][open] != -1)
            return dp[i][open];
        if (s[i] == ')')
            return dp[i][open] = open && dfs(s, i + 1, open - 1);
        if (s[i] == '*')
            return dp[i][open] = (open && dfs(s, i + 1, open - 1)) || dfs(s, i + 1, open + 1) || dfs(s, i + 1, open);
        return dp[i][open] = dfs(s, i + 1, open + 1);
    }

public:
    bool checkValidString(string s)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, 0);
    }
};

// Time Complexity - O(N * 3^N)
// Space Complexity - O(N)

class Solution
{
    bool dfs(string &s, string st, int i)
    {
        if (i == s.size())
            return st.empty();
        if (s[i] == ')')
        {
            if (st == "")
                return 0;
            st.pop_back();
            return dfs(s, st, i + 1);
        }
        if (s[i] == '*')
        {
            int res = 0;
            if (st.back() == '(')
            {
                st.pop_back();
                res |= dfs(s, st, i + 1);
                st += '(';
            }
            return res | dfs(s, st + '(', i + 1) | dfs(s, st, i + 1);
        }
        return dfs(s, st + s[i], i + 1);
    }

public:
    bool checkValidString(string s)
    {
        return dfs(s, "", 0);
    }
};