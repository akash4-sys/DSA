#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

long long mod = 1e9 + 7;

long long power(long long a, long long b)
{
    long long res = 1;
    for (a %= mod; b > 0; b >>= 1) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

int main()
{
    long long n;
    cin >> n;
    cout << power(2, n);
    return 0;
}