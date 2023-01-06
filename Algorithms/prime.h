#pragma once

#include "vector"
#include "cmath"

using namespace std;

class Prime
{
public:
    bool isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return 0;
        return 1;
    }

    // Time Complexity - O(Nlog(log(N)))
    void sieve(int n)
    {
        vector<int> prime(n + 1, 1);
        for (int p = 2; p * p <= n; p++)
            if (prime[p])
                for (int i = p * p; i <= n; i += p)
                    prime[i] = 0;
    }


    // Time Complexity - O(N)
    void msieve(int n)
    {
        vector<long long> isprime(100, true), prime, SPF(100);
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
};