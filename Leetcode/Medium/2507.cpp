#include "../../headers.h"

class Solution
{
    int primeFactors(int n)
    {
        int sum = 0;
        while (n % 2 == 0)
            sum += 2, n = n / 2;
            
        for (int i = 3; i <= sqrt(n); i = i + 2)
            while (n % i == 0)
                sum += i, n = n / i;

        if (n > 2)
            sum += n;
        return sum;
    }

public:
    int smallestValue(int n)
    {
        int p = INT_MAX;
        while(p > n)
        {
            int x = primeFactors(n);
            p = n;
            n = x;
        }
        return n;
    }
};