#pragma once

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// GCD of an array
int GCD(vector<int> &v)
{
    int maxi = INT_MIN, mini = INT_MAX;
    for (int n : v)
        maxi = max(maxi, n), mini = min(mini, n);
    return gcd(maxi, mini);
}

// number of common Factors
int commonFactors(int a, int b)
{
    int x = gcd(a, b), ans = 0;
    for (int i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0)
            ans += x / i == i ? 1 : 2;
    return ans;
}

// Common factors
void factors(int x)
{
    for (int i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0)
        {
            if (x / i == i)
                cout << " " << i;
            else
                cout << " " << i << " " << x / i;
        }
}


// Binary Exponentiation
// For very large values
int power(long base, long n)
{
    long ans = 1, mod = (long)1e9 + 7;
    for (; n; n /= 2)
    {
        if (n % 2 == 1)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
    }
    return (ans - 2 + mod) % mod;
}