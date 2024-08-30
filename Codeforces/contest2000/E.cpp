#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

ll f(ll n, ll k, ll i) {
    return min(i, n - k) - max(i + 1 - k, 0LL) + 1;
}

ll solve()
{
    ll n = LL, m = LL, k = LL, g = LL, ans = 0;
    vec a(g), cnt;
    iv(a);
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cnt.push_back(f(n, k, i) * f(m, k, j));

    sort(all(a), greater<ll>());
    sort(all(cnt), greater<ll>());
    for (int i = 0; i < g; i++)
        ans += (cnt[i] * a[i]);
    return ans;
}

int main()
{
    fast;
    for (int tc = LL; tc; tc--)
        cout << solve() << "\n";
    return 0;
}