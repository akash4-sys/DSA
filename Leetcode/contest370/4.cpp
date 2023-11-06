#include "../../headers.h"

class Solution
{
public:
    long long maxBalancedSubsequenceSum(vector<int> &v)
    {
        map<int, long long> mp;
        for (int i = 0; i < v.size(); i++)
        {
            long long pos = v[i] - i, sum = v[i];
            if (auto it = mp.upper_bound(v[i] - i); it != begin(mp))
                sum = max(sum, sum + prev(it)->second);
            mp[pos] = sum;
        }

        return max_element(begin(mp), end(mp), [&](auto &p1, auto &p2){
            return p1.second < p2.second;
        })->second;
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
    long long n, dp[100001];
    long long rec(vector<int> &v, int i)
    {
        if (dp[i] != -1)
            return dp[i];

        long long res = 0;
        for (int j = i + 1; j < n; j++)
            if (v[j] - v[i] >= j - i)
                res = max(res, rec(v, j) + v[j]);
        return dp[i] = res;
    }

public:
    long long maxBalancedSubsequenceSum(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        n = v.size();

        long long ans = 0, neg = 0, mx = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(rec(v, i) + v[i], ans);
            neg += v[i] < 0;
            mx = max(mx, (long long)v[i]);
        }
        return neg == n ? mx : ans;
    }
};