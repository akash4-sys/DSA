#include "headers.h"

vector<int> prime;
void sieve(int n)
{
    prime = vector<int>(n + 1, 0);
    for (long p = 2; p <= n; p++)
    {
        if (prime[p] != 0)
            continue;
        prime[p] = p;
        for (long i = p * p; i <= n; i += p)
            if (!prime[i])
                prime[i] = p;
    }
}

class Solution
{
    vector<int> distinctPF(int n)
    {
        vector<int> res;
        while (n != 1)
        {
            int p = prime[n];
            while (n % p == 0)
                n /= p;
            res.push_back(p);
        }
        return res;
    }

    int connectedNodes(vector<vector<int>> &g, vector<int> &vis, int u)
    {
        vis[u] = 1;
        int res = 1;
        for (int v : g[u])
            if (!vis[v])
                res += connectedNodes(g, vis, v);
        return res;
    }

public:
    bool canTraverseAllPairs(vector<int> &v)
    {
        if (prime.empty())
            sieve(1e5 + 1);

        int n = v.size();
        if (n == 1)
            return 1;
        
        vector<vector<int>> g(n);
        vector<int> vis(n, 0);
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (v[i] == 1)
                return 0;
            auto pf = distinctPF(v[i]);
            for (auto p : pf)
            {
                if (mp.count(p)) {
                    g[i].push_back(mp[p]);
                    g[mp[p]].push_back(i);
                }
                mp[p] = i;
            }
        }
        return connectedNodes(g, vis, 0) == n;
    }
};