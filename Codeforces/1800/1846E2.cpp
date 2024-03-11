#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
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

string solve()
{
    ll n = LL, l = 2, r = 1e9;
    while (l <= r)
    {
        ll k = (l + r) / 2;
        set<ll> st;
        for (ll sum = 1 + k, leafs = k * k; sum + leafs <= n; leafs *= k)
            st.insert(sum += leafs);
        
        auto it = st.lower_bound(n);
        if (*it == n)
            return "YES";
        if (*it > n)
            r = k - 1;
        else
            l = k + 1;
    }
    return "NO";
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        pl(solve());
    return 0;
}