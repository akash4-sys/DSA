#include "headers.h"

class Solution
{
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    vector<int> closestPrimes(int l, int r)
    {
        vector<int> v;
        for (int i = l; i <= r; i++)
            if (isPrime(i))
                v.push_back(i);
            
        if(!v.size())
            return {-1, -1};

        int diff = INT_MAX;
        for (int i = 0; i < v.size() - 1; ++i)
            diff = min(v[i + 1] - v[i], diff);

        for (int i = 0; i < v.size() - 1; ++i)
            if (v[i + 1] - v[i] == diff)
                return {v[i], v[i + 1]};
        return {-1, -1};
    }
};