#pragma once

#include <vector>
#include <cmath>
#include <set>

using namespace std;

class Prime
{
public:
    bool isPrime(int n)
    {
        if (n == 1)
            return 0;
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            if (n % i == 0)
                return 0;
        return 1;
    }

    // p * p == sqrt(n)
    // Time Complexity - O(Nlog(log(N)))
    // sqrt(n) > log(n)  // hence sieve algo is faster than isPrime -- check (204)

    void sieve(int n)
    {
        vector<int> prime(n + 1, 1);
        prime[1] = 0;
        for (int p = 2; p * p <= n; p++)
            for (int i = p * p; i <= n && prime[p]; i += p)
                prime[i] = 0;
    }


    // Time Complexity - O(N)
    void msieve(int n)
    {
        vector<int> smallest_prime_fact(n + 1, 0), prime;
        smallest_prime_fact[1] = 1; 
        for (int i = 2; i <= n; i++)
        {
            if (!smallest_prime_fact[i])
                smallest_prime_fact[i] = i, prime.push_back(i);
            for (int j = 0; j < prime.size() && i * prime[j] <= n && prime[j] <= smallest_prime_fact[i]; j++)
                smallest_prime_fact[i * prime[j]] = prime[j];
        }
    }

    // Time Complexity - O(sqrt(n))
    set<int> distinctPrimeFactors(int n)
    {
        set<int> s;
        if (n == 2)
            s.insert(n);
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            for (; !(n % i); n /= i)
                s.insert(i);
        if (n > 2)
            s.insert(n);
        return s;
    }
};