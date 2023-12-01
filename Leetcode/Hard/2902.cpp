#include "../../headers.h"

// Time Complexity - O(sqrt(r))
// Space Complexity - O(r)

class Solution
{
public:
    int countSubMultisets(vector<int> &v, int l, int r)
    {
        int ans = 0, mod = 1e9 + 7;
        vector<int> dp(r + 1, 0);
        dp[0] = 1;
        unordered_map<int, int> mp;
        for (int a : v)
            mp[a]++;
        
        for (auto [a, c] : mp)
            for (int sum = r; sum > max(0, r - a); sum--)
            {
                int csum = 0;
                for (int k = 0; k < c && (a * k) <= sum; k++)
                    csum = (csum + dp[sum - a * k]) % mod;
                
                for (int i = sum; i > 0; i -= a)
                {
                    if (a * c <= i)
                        (csum += dp[i - a * c]) %= mod;
                    csum = (csum - dp[i] + mod) % mod;
                    dp[i] = (dp[i] + csum) % mod;
                }
            }

        while (l <= r)
            ans = (ans + dp[l++]) % mod;
        return 1LL * ans * (mp[0] + 1) % mod;
    }
};


// Time Complexity - O(N * Sqrt(N))
// Space Complexity  - O(N * Sqrt(N))

class Solution
{
    int mod = 1e9 + 7, dp[201][20001];
    vector<vector<int>> v;

    int rec(int i, int sum)
    {
        if (i == v.size())
            return 1;
        if (dp[i][sum] != -1)
            return dp[i][sum];

        int res = 0, a = v[i][0], n = v[i][1];
        for (int k = 1; k <= n && (a * k) <= sum; k++)
            res = (res + rec(i + 1, sum - (a * k))) % mod;

        return dp[i][sum] = (res + rec(i + 1, sum)) % mod;
    }

public:
    int countSubMultisets(vector<int> &nums, int l, int r)
    {
        unordered_map<int, int> mp;
        for (int a : nums)
            mp[a]++;
        for (auto [n, c] : mp)
            v.push_back({n, c});

        memset(dp, -1, sizeof(dp));
        int ans = rec(0, r) - (l > 0 ? rec(0, l - 1) : 0);
        return (ans + mod) % mod;
    }
};