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

ll calc(multiset<ll> &st)
{
    auto l = st.begin();
    auto r = st.rbegin();
    if (l != st.end() && r != st.rend());
        return *r - *l;
    return 0;
}

ll solve()
{
    ll n = LL, time = LL, ans = 0, sum = 0;
    vv v;
    for (int i = 0; i < n; i++)
        v.push_back({LL, LL});
    
    sort(all(v));
    multiset<ll> st;
    for (int l = 0, r = 0; r < n; r++)
    {
        sum += v[r][0];
        st.insert(v[r][1]);
        while (l <= r && sum + calc(st) > time) {
            sum -= v[l][0];
            st.erase(v[l][1]);
            l++;
        }
        ans = max(ans, (ll)st.size());
    }
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