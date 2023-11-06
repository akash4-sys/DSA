#include "../../headers.h"

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int mod = 1e9 + 7;
        long long ans = 0;
        unordered_map<int, long long> umap;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            umap[arr[i]] = 1;
            for (int j = 0; j < i; j++)
                if (arr[i] % arr[j] == 0)
                    umap[arr[i]] = (umap[arr[i]] + (umap[arr[j]] * umap[arr[i] / arr[j]])) % mod;

            ans = (ans + umap[arr[i]]) % mod;
        }
        return ans;
    }
};


class Solution
{
    int mod = 1e9 + 7;
    unordered_map<int, long long> dp;

    int rec(unordered_set<int> &st, int n)
    {
        if (dp.count(n))
            return dp[n];

        long long res = 1;
        for (int x : st)
            if (n % x == 0 && st.count(n / x))
                (res += (1LL * rec(st, x) * rec(st, n / x)) % mod) %= mod;
        return dp[n] = res;
    }

public:
    int numFactoredBinaryTrees(vector<int> &v)
    {
        unordered_set<int> st(v.begin(), v.end());
        int ans = 0;
        for (int n : v)
            (ans += rec(st, n)) %= mod;
        return ans;
    }
};