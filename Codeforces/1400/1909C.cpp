#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
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
    int n = II;
    vec l(n), r(n), c(n), d;
    iv(l); iv(r); iv(c);
    sort(all(l));
    sort(all(c));

    set<ll> st;
    for (ll &a : r)
        st.insert(a);
    
    for (int i = n - 1; i >= 0; i--) {
        auto it = st.upper_bound(l[i]);
        d.push_back(*it - l[i]);
        st.erase(it);
    }

    ll ans = 0;
    sort(all(d));
    for (int i = 0; i < n; i++)
        ans += (d[i] * c[n - i - 1]);
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}