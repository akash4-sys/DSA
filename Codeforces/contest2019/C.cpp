#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

ll solve()
{
    ll n = LL, k = LL, m = 0, x = 0;
    for (int i = 0; i < n; i++) {
        ll a = LL;
        m += a;
        x = max(x, a);
    }

    for (ll s = n; s > 0; s--) {
        ll need = x * s;
        if (m <= need && need - m <= k)
            return s;
        if (m > need && (s - (m % s)) % s <= k)
            return s;
    }
    return 100;
}

int main()
{
    fast;
    for (ll tc = LL; tc; tc--)
        cout << solve() << "\n";
    return 0;
}