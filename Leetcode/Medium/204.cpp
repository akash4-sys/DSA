#include "../../headers.h"

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> prime(n, 1);
        int ans = 0;
        for (int p = 2; p < n; p++)
        {
            ans += prime[p];
            for (long i = (long)p * p; i < n && prime[p]; i += p)
                prime[i] = 0;
        }
        return ans;
    }
};


// Time Complexity - O(Nlog(logN))
// Space Compexity - O(N)

class Solution
{
    vector<int> prime;
    void sieve(int n)
    {
        for (int p = 2; p * p <= n; p++)
            for (int i = p * p; i <= n && prime[p]; i += p)
                prime[i] = 0;
    }

public:
    int countPrimes(int n)
    {
        prime = vector<int>(n + 1, 1);
        sieve(n);
        int ans = 0;
        for (int i = 2; i < n; i++)
            ans += prime[i];
        return ans;
    }
};


// Time Complexity - O(N * sqrt(n))
// TLE
class Solution
{
    bool isPrime(int n)
    {
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            if (n % i == 0)
                return 0;
        return 1;
    }

public:
    int countPrimes(int n)
    {
        int ans = 0;
        for (int i = 2; i < n; i++)
            ans += isPrime(i);
        return ans;
    }
};