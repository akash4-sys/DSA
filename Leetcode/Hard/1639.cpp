#include "../../headers.h"

class Solution
{
public:
    int numWays(vector<string> &v, string t)
    {
        int mod = 1e9 + 7, m = v[0].size(), k = t.size();
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++)
        {
            vector<int> ch(26, 0);
            for (auto &s : v)
                ch[s[i] - 'a']++;
            for (int j = k - 1; j >= 0; j--)
                (dp[j + 1] += dp[j] * ch[t[j] - 'a']) %= mod;
        }
        return dp[k];
    }
};


class Solution
{
public:
    int numWays(vector<string> &v, string t)
    {
        int mod = 1e9 + 7, m = v[0].size(), k = t.size();
        vector dp(m, vector<long long>(k, 0)), mp(m, vector<long long>(26, 0));
        for (string &s : v)
            for (int j = 0; j < m; j++)
                mp[j][s[j] - 'a']++;
        
        dp[0][0] = 1;
        for (int i = 0; i <= k; i++)
            for (int j = 0; j < m; j++)
            {
                if (i < k)
                    (dp[i + 1][j + 1] += (mp[j][t[i] - 'a'] * dp[i][j])) %= mod;
                (dp[i][j + 1] += dp[i][j]) %= mod;
            }
        return dp[m][k];
    }
};


class Solution
{
public:
    int numWays(vector<string> &v, string t)
    {
        int mod = 1e9 + 7, m = v[0].size(), k = t.size();
        vector dp(m, vector<int>(k, -1)), mp(m, vector<int>(26, 0));
        for (string &s : v)
            for (int j = 0; j < m; j++)
                mp[j][s[j] - 'a']++;

        function<long long(int, int)> dfs = [&](int i, int j) -> long long {
            if (j == k)
                return 1;
            if (i == m)
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            dp[i][j] = dfs(i + 1, j);
            return dp[i][j] = (dp[i][j] + (mp[i][t[j] - 'a'] * dfs(i + 1, j + 1))) % mod;
        };
        return dfs(0, 0);
    }
};