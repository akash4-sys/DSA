#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

ll check(vec &a, ll k, ll d)
{
    k++;
    ll n = a.size(), coins = 0, m = min(n, k);
    vec v(n, -1);
    for (ll i = 0, day = 0; day < d; day++, i = (i + 1) % m)
    {
        if (day >= v[i])
            coins += a[i];
        else if (day < v[i] && v[i] < d)
            coins += a[i], day = v[i];
        v[i] = day + k;
    }
    return coins;
}

ll solve()
{
    ll n = LL, c = LL, d = LL, l = 0, r = d + 2, ans = -1, sum = 0;
    vec a(n);
    iv(a);

    sort(all(a), greater<ll>());
    for (int i = 0; i < min(n, d); i++)
        sum += a[i];

    if (sum >= c)
        return -2;
    if (a[0] * d < c)
        return -1;
    
    while (l <= r)
    {
        ll mid = l + ((r - l) / 2);
        if (check(a, mid, d) >= c)
            l = mid + 1, ans = max(ans, mid);
        else
            r = mid - 1;
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        ll ans = solve();
        if (ans == -1)
            pl("Impossible");
        else if (ans == -2)
            pl("Infinity");
        else
            pl(ans);
    }
    return 0;
}