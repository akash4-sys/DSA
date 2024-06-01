#include "../../headers.h"

class Solution
{
    vector<int> prime;
    void sieve(int n)
    {
        prime = vector<int>(n + 1, 1);
        prime[1] = 0;
        for (int p = 2; p * p <= n; p++)
            for (int i = p * p; i <= n && prime[p]; i += p)
                prime[i] = 0;
    }

public:
    int maximumPrimeDifference(vector<int> &v)
    {
        sieve(100);
        int i = 0, n = v.size(), j = n - 1;
        for (; i < n && !prime[v[i]]; i++);
        for (; j >= 0 && !prime[v[j]]; j--);
        return abs(i - j);
    }
};