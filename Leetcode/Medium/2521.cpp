#include "../../headers.h"

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    int distinctPrimeFactors(vector<int> &v)
    {
        unordered_set<int> s;
        for (int n: v)
        {
            if (n == 2)
                s.insert(n);
            for (int i = 2, sq = sqrt(n); i <= sq; i++)
                for (; !(n % i); n /= i)
                    s.insert(i);
            if (n > 2)
                s.insert(n);
        }
        return s.size();
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution 
{
    vector<int> prime;
    void sieve(int n)
    {
        for (int p = 2; p * p <= n; p++)
            if (prime[p])
                for (int i = p * p; i <= n; i += p)
                    prime[i] = 0;
    }

    void primeFactors(int n, unordered_set<int> &s)
    {
        for (int i = 2; i < n; i++)
            if (prime[i] && n % i == 0)
                s.insert(i);
    }

public:
    int distinctPrimeFactors(vector<int>& v)
    {
        int maxn = *max_element(v.begin(), v.end());
        prime = vector<int>(maxn + 1, 1);
        sieve(maxn);
        unordered_set<int> s;

        for (int n : v)
            if (prime[n])
                s.insert(n);
            else
                primeFactors(n, s);
        return s.size();
    }
};