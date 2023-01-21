#pragma once

#include "vector"
#include "cmath"
#include "unordered_set"

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
        for (int p = 2; p * p <= n; p++)
            for (int i = p * p; i <= n && prime[p]; i += p)
                prime[i] = 0;
    }


    // Time Complexity - O(N)
    void msieve(int n)
    {
        vector<long long> isprime(100, true), SPF(100);
        vector<long long>  prime;
        isprime[0] = isprime[1] = false;
        for (long long int i = 2; i < n; i++)
        {
            if (isprime[i])
                prime.push_back(i), SPF[i] = i;
            for (long long int j = 0; j < (int)prime.size() && i * prime[j] < n && prime[j] <= SPF[i]; j++)
            {
                isprime[i * prime[j]] = false;
                SPF[i * prime[j]] = prime[j];
            }
        }
    }

    // Time Complexity - O(sqrt(n))
    void distinctPrimeFactors(int n)
    {
        unordered_set<int> s;
        if (n == 2)
            s.insert(n);
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            for (; !(n % i); n /= i)
                s.insert(i);
        if (n > 2)
            s.insert(n);
    }
};