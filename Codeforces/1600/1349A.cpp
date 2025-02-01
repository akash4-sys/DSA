#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), pfGCD(n);
    for (ll i = 0, g = 0; i < n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        pfGCD[i] = g;
    }

    ll g = 0;
    for (int i = n - 1; i > 0; i--)
        g = __gcd(g, (a[i] * pfGCD[i - 1]) / __gcd(a[i], pfGCD[i - 1]));
    cout << g;
    return 0;
}