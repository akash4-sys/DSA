#include "../headers.h"

int mod = 1e9 + 7, dp[101][11];
class Solution
{
    int dfs(string &s, int i, int p, int limit)
    {
        if (p < 0 || p > 9 || (limit && p > s[s.size() - i] - '0'))
            return 0;
        if (i == 1)
            return 1;
        limit &= p == s[s.size() - i] - '0';
        if (limit)
            return (dfs(s, i - 1, p - 1, limit) + dfs(s, i - 1, p + 1, limit)) % mod;
        if (dp[i][p] == 0)
            dp[i][p] = (dfs(s, i - 1, p - 1, limit) + dfs(s, i - 1, p + 1, limit)) % mod;
        return dp[i][p];
    }

    int count(string &s)
    {
        int res = 0;
        for (int i = 1; i <= s.size(); i++)
            for (int d = 1; d <= 9; d++)
                (res += dfs(s, i, d, i == s.size())) %= mod;
        return res;
    }

public:
    int countSteppingNumbers(string low, string high)
    {
        return (mod + count(high) - count(low) +
            equal(low.begin() + 1, low.end(), low.begin(), [&](int a, int b) {
                return abs(a - b) == 1;
            })
        ) % mod;
    }
};



// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    int mod = 1e9 + 7, dp[101][11][2][2];
    int dfs(string &s, int i, int p, int t, int zero)
    {
        if (i == s.size())
            return !zero;
        if (dp[i][p][t][zero] != -1)
            return dp[i][p][t][zero];

        int res = 0, limit = t ? s[i] - '0' : 9;
        for (int d = 0; d <= limit; d++)
        {
            int tight = t && d < limit ? 0 : t;
            int z = zero && d > 0 ? 0 : zero;
            if (zero || abs(d - p) == 1)
                (res += dfs(s, i + 1, d, tight, z)) %= mod;
        }
        return dp[i][p][t][zero] = res;
    }

public:
    int countSteppingNumbers(string low, string high)
    {
        memset(dp, -1, sizeof(dp));
        long long l = dfs(low, 0, 0, 1, 1);

        memset(dp, -1, sizeof(dp));
        int r = dfs(high, 0, 0, 1, 1), isStepNum = 1;

        for (int i = 1; i < low.size() && isStepNum; i++)
            if (abs(low[i - 1] - low[i]) != 1)
                isStepNum = 0;
        return (((r - l + isStepNum) % mod) + mod) % mod;
    }
};

// Time Complexity - TLE
// Space Complexity - O(N)

class Solution
{
    int mod = 1e9 + 7;
    bool lt(string &s, string r)
    {
        if (r.size() != s.size())
            return r.size() < s.size();
        for (int i = 0; i < s.size(); i++)
            if (s[i] != r[i])
                return s[i] > r[i];
        return 0;
    }

    int rec(string &s, string r)
    {
        if (!lt(s, r))
            return 0;

        int res = !r.empty();
        for (int i = 1; i <= 9 && r.empty(); i++)
            (res += rec(s, r + to_string(i))) %= mod;

        int d = r.size() ? r.back() - '0' : -1;
        if (d >= 1)
            (res += rec(s, r + to_string(d - 1))) %= mod;
        if (d < 9 && d > -1)
            (res += rec(s, r + to_string(d + 1))) %= mod;
        return res;
    }

public:
    int countSteppingNumbers(string low, string high)
    {
        int l = rec(low, ""), r = rec(high, ""), isStepNum = 1;
        for (int i = 1; i < high.size() && isStepNum; i++)
            if (abs(high[i - 1] - high[i]) != 1)
                isStepNum = 0;
        return r - l + isStepNum;
    }
};