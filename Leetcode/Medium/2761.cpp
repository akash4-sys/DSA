#include "headers.h"

class Solution
{
    vector<int> prime, p;
    void sieve(int n)
    {
        prime = vector<int>(n + 1, 1);
        for (int x = 2; x * x <= n; x++)
            for (int i = x * x; i <= n && prime[x]; i += x)
                prime[i] = 0;

        prime[0] = prime[1] = 0;
        for (int i = 2; i <= n; i++)
            if (prime[i])
                p.push_back(i);
    }

public:
    vector<vector<int>> findPrimePairs(int n)
    {
        sieve(n);
        vector<vector<int>> ans;
        for (int x : p)
            if (prime[n - x])
                prime[x] = 0, ans.push_back({x, n - x});
        return ans;
    }
};