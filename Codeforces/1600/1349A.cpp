#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define II ({ int a; cin >> a ; a; })

int main()
{
    ll n = II, a = II, b = II;
    ll k = __gcd(a, b), g = a * b;
    for (int i = 2; i < n; i++) {
        ll x = II;
        g = __gcd(g, k * x);
        k = __gcd(k, x);
    }
    cout << g / k;
    return 0;
}