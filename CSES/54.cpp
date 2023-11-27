#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long

vector<ll> dp;
int mod = 1e9 + 7;

ll rec(ll n)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    ll res = 0;
    for (int i = 1; i <= 6; i++)
        if (n >= i)
            (res += rec(n - i)) %= mod;
    return dp[n] = res;
}

int main()
{
    ll n;
    cin >> n;
    dp.resize(n + 1, -1);
    cout << rec(n);
    return 0;
}