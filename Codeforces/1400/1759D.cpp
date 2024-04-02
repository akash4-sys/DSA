#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

ll solve()
{
    ll n = LL, m = LL, cnt2 = 0, cnt5 = 0, k = 1;
    for (ll x = n; x % 2 == 0; x /= 2, cnt2++);
    for (ll x = n; x % 5 == 0; x /= 5, cnt5++);
    
    ll p = abs(cnt5 - cnt2), q = cnt2 < cnt5 ? 2 : 5;
    for (; p && k * q <= m; p--, k *= q);
    for (; k * 10 <= m; k *= 10);
    return k == 1 ? n * m : k * (m / k) * n;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}