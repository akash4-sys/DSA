#include <bits/stdc++.h>

using namespace std;

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

ll solve()
{
    ll n = II, k = II;
    vec v(n), r(n);
    iv(v);

    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        ll x = ceil((v.back() - v[i]) / (k * 1.0));
        r[i] = v[i] + (x * k);
        if (x % 2 == 0)
            v[i] = r[i], r[i] += k - 1;
        else
            r[i]--;
    }

    int low = *max_element(all(v)), high = *min_element(all(r));
    if (high - low >= 0)
        return low;
    return -1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}