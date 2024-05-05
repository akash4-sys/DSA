#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

int main()
{
    fast;
    ll n = LL, m = LL, q = LL, g = __gcd(n, m);
    while (q--)
    {
        ll sx = LL, sy = LL, ex = LL, ey = LL;
        ll k1 = sx == 1 ? n / g : m / g;
        ll k2 = ex == 1 ? n / g : m / g;
        ll s_pos = ceil((long double) sy / k1);
        ll e_pos = ceil((long double) ey / k2);
        cout << (s_pos == e_pos ? "YES" : "NO") << "\n";
    }
    return 0;
}