#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long

int main()
{
    ll n, q, a, b, x = 0;
    cin >> n >> q;
    vector<ll> v(n + 1, 0);
    for (ll i = 1, m; i <= n; i++)
    {
        cin >> m;
        x ^= m;
        v[i] = x;
    }

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        cout << (v[b] ^ v[a - 1]) << endl;
    }
    return 0;
}