#include "../../headers.h"

class Solution
{
    vector<string> ans;
    void dfs(string &s, int t, string exp, int i, long val, long prev)
    {
        if (i == s.size())
        {
            if (val == t)
                ans.push_back(exp);
            return;
        }

        string r;
        long n = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (j > i && s[i] == '0')
                return;
            r += s[j];
            n = (n * 10) + (s[j] - '0');
            if (i == 0)
                dfs(s, t, exp + r, j + 1, n, n);
            else
            {
                dfs(s, t, exp + "+" + r, j + 1, val + n, n);
                dfs(s, t, exp + "-" + r, j + 1, val - n, -n);
                dfs(s, t, exp + "*" + r, j + 1, (val - prev) + (prev * n), prev * n);
            }
        }
    }

public:
    vector<string> addOperators(string s, int t)
    {
        dfs(s, t, "", 0, 0, 0);
        return ans;
    }
};