#include "../../headers.h"

class Solution
{
    bool isHamming(string &s, string &r)
    {
        if (s.size() != r.size())
            return 0;
        int d = 0;
        for (int i = 0; i < s.size(); i++)
            d += s[i] != r[i];
        return d == 1;
    }

    vector<int> ans;

    int rec(vector<string> &v, vector<int> &g, vector<int> &dp, vector<int> &idx, int i)
    {
        if (i == v.size())
            return 0;
        
        int res = 0, nextIdx = -1;
        if (i != -1 && dp[i] != -1)
        {
            idx.push_back(dp[i]);
            res = rec(v, g, dp, idx, dp[i]) + 1;
            idx.pop_back();
            return res;
        }
        
        for (int j = i + 1; j < v.size(); j++)
            if (i == -1 || (g[i] != g[j] && isHamming(v[i], v[j])))
            {
                idx.push_back(j);
                int len = rec(v, g, dp, idx, j) + 1;
                idx.pop_back();
                if (len > res)
                    res = len, nextIdx = j;
            }
        
        if (idx.size() > ans.size())
            ans = idx;
        if (i != -1)
            dp[i] = nextIdx;
        return res;
    }

public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string> &v, vector<int> &g)
    {
        vector<int> dp(n, -1), idx;
        rec(v, g, dp, idx, -1);
        vector<string> res;
        for (int i : ans)
            res.push_back(v[i]);
        return res;
    }
};