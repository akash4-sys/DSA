#include "../../headers.h"

class Solution
{
    long long mod = 1e9 + 7;
    vector<vector<long long>> ncr;

    long long dfs(vector<int> &v)
    {
        int n = v.size();
        if (n <= 2)
            return 1;
        
        vector<int> l, r;
        for (int i = 1; i < n; i++)
            if (v[i] < v[0])
                l.push_back(v[i]);
            else
                r.push_back(v[i]);
        
        long long leftWays = dfs(l), rightWays = dfs(r);
        return (((leftWays * rightWays) % mod) * ncr[n - 1][l.size()]) % mod;
    }

public:
    int numOfWays(vector<int> &v)
    {
        int n = v.size();
        ncr.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            ncr[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; j++)
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
        }
        return (dfs(v) - 1) % mod;
    }
};