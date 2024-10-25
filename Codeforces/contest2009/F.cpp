#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    ll n = LL, q = LL;
    vector<ll> a(n), pf(1, 0);
    iv(a);
    for (ll &x : a)
        pf.push_back(pf.back() + x);
    for (ll &x : a)
        pf.push_back(pf.back() + x);
    
    while (q--)
    {
        ll l = LL - 1, r = LL - 1, i = l / n, j = r / n;
        l %= n, r %= n;
        ll full = pf[n] * (j - i + 1);
        ll start = pf[i + l] - pf[i];
        ll end = pf[j + n] - pf[j + r + 1];
        cout << full - start - end << "\n";
    }
}

int main()
{
    fast;
    for (int tc = LL; tc; tc--)
        solve();
    return 0;
}