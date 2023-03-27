#include "../../headers.h"

vector<int> prime;
class Solution
{
    void sieve()
    {
        vector<int> pm(1001, 1);
        for (int p = 2; p * p <= 1000; p++)
            for (int i = p * p; i <= 1000 && pm[p]; i += p)
                pm[i] = 0;
        for (int i = 2; i < 1001; i++)
            if (pm[i])
                prime.push_back(i);
    }

public:
    bool primeSubOperation(vector<int> &v)
    {
        if (prime.empty()) sieve();
        int l = 0;
        for (int n : v)
        {
            int i = 0;
            for (; i < prime.size() && n - prime[i] > l; i++);
            i = max(i - 1, 0);
            if (n - prime[i] <= l && n <= l)
                return 0;
            l = n - prime[i] > l ? n - prime[i] : n;
        }
        return 1;
    }
};