#include "headers.h"

// Faster
// Time Complexity - O(Nlog(log(N)))
// Space Complexity - O(N)

class Solution 
{
public:
    vector<int> closestPrimes(int l, int r) 
    {
        vector<int> v, prime(r + 1, 1);
        for (int p = 2; p <= r; p++)
        {
            if (prime[p] && p >= l)
                v.push_back(p);
            for (long long i = (long long)p * p; i <= r && prime[p]; i += p)
                prime[i] = 0;
        }
        
        int d = INT_MAX, x = -1, y = -1;
        for (int i = 0; i < v.size() - 1 && v.size(); i++)
            if (v[i + 1] - v[i] < d)
                x = v[i], y = v[i + 1], d = y - x;
        return {x, y};
    }
};


// Time Complexity - O(N*sqrt(N))
// Space Complexity - O(N)

class Solution 
{
    bool isPrime(int n)
    {
        if (n == 1)
            return 0;
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            if (n % i == 0)
                return 0;
        return 1;
    }

public:
    vector<int> closestPrimes(int l, int r) 
    {
        vector<int> v;
        for (; l <= r; l++)
            if (isPrime(l))
                v.push_back(l);
        
        int d = INT_MAX, x = -1, y = -1;
        for (int i = 0; i < v.size() - 1 && v.size(); i++)
            if (v[i + 1] - v[i] < d)
                x = v[i], y = v[i + 1], d = y - x;
        return {x, y};
    }
};