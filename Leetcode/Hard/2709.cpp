#include "../../headers.h"


class DSU
{
    vector<int> parent;

public:
    DSU(int n) : parent(n) { iota(parent.begin(), parent.end(), 0); }

    int par(int u)
    {
        return parent[u] == u ? u : parent[u] = par(parent[u]);
    }

    bool Union(int u, int v)
    {
        int uPar = par(u), vPar = par(v);
        if (uPar == vPar)
            return 0;
        parent[uPar] = vPar;
        return 1;
    }
};

class Solution
{
    unordered_set<int> pf(int n)
    {
        unordered_set<int> s;
        if (n == 2)
            s.insert(n);
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            for (; !(n % i); n /= i)
                s.insert(i);
        if (n > 2)
            s.insert(n);
        return s;
    }

public:
    bool canTraverseAllPairs(vector<int> &v)
    {
        DSU uf(1e5 + 1);
        for (int a : v)
            for (int p : pf(a))
                uf.Union(a, p);

        for (int i = 1; i < v.size(); i++)
            if (uf.par(v[i - 1]) != uf.par(v[i]) || v[i - 1] == 1)
                return 0;
        return 1;
    }
};



// Time Complexity - O(NlogN)
// Space Complexity - O(N)

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