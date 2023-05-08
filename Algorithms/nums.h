#pragma once

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// number of common Factors
int commonFactors(int a, int b)
{
    int x = gcd(a, b), ans = 0;
    for (int i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0)
            ans += x / i == i ? 1 : 2;
    return ans;
}

// factors
void factors(int x)
{
    for (int i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0)
        {
            if (x / i != i)
                cout << " " << x / i;
            cout << " " << i;
        }
}

// Binary Exponentiation
// For very large values
long long power(long long a, long long b, long long mod)
{
    long long res = 1;
    for (a %= mod; b > 0; b >>= 1)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

// factorial of a number
long long fact(int x)
{
    int mod = 1e9 + 7;
    long long res = 1;
    for (long long i = 1; i <= x; i++)
        res = (res * i) % mod;
    return res;
}

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// find min positive multiple of a number for k
// i.e. for n = -10 & k = 3, minPos = 2
int minPos(int n, int k)
{
    return ((n % k) + k) % k;
}