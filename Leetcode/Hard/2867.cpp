#include "../../headers.h"

class Solution
{
    long long ans = 0;
    vector<int> prime;

    void sieve(int n)
    {
        for (int p = 2; p * p <= n; p++)
            for (int i = p * p; i <= n && prime[p]; i += p)
                prime[i] = 0;
        prime[1] = 0;
    }

    pair<int, int> dfs(vector<vector<int>> &g, int u, int par)
    {
        int curr_notprime = !prime[u], curr_prime = prime[u];
        for (int v : g[u])
            if (v != par)
            {
                auto [not_prime, isprime] = dfs(g, v, u);
                ans += (not_prime * curr_prime) + (isprime * curr_notprime);
                if (prime[u])
                    curr_prime += not_prime;
                else
                    curr_notprime += not_prime, curr_prime += isprime;
            }
        return {curr_notprime, curr_prime};
    }

public:
    long long countPaths(int n, vector<vector<int>> &edges)
    {
        prime = vector<int>(n + 1, 1);
        sieve(n);
        vector g(n + 1, vector<int>());
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        
        dfs(g, 1, 0);
        return ans;
    }
};