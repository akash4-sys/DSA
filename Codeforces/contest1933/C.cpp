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

long long pow(long long a, long long b)
{
    long long res = 1;
    for (; b > 0; b >>= 1)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
    }
    return res;
}

ll solve()
{
    ll a = LL, b = LL, l = LL;
    set<ll> st;
    for (ll x = 0; x <= 20 && pow(a, x) <= l; x++)
        for (ll y = 0; y <= 20 && pow(b, y) <= l; y++)
        {
            ll f = pow(a, x) * pow(b, y);
            if (l % f == 0)
                st.insert(l / f);
        }
    return st.size();
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}