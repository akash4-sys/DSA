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
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    ll n = LL, ans = 0, mn = LLONG_MAX, mn2 = mn;
    for (int i = 0; i < n; i++)
    {
        ll m = LL;
        priority_queue<ll, vec, greater<ll>> pq;
        for (int j = 0; j < m; j++)
            pq.push(LL);
        
        mn = min(pq.top(), mn);
        pq.pop();
        mn2 = min(pq.top(), mn2);
        ans += pq.top();
    }
    return ans - mn2 + mn;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}