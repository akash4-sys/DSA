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

vec solve()
{
    ll n = II, k = II, q = II;
    vec a(k), b(k), ans;
    iv(a); iv(b);
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);
    
    while (q--)
    {
        ll target = II;
        ll i = upper_bound(all(a), target) - a.begin();
        if (i > k)
            i--;
        
        ll res = b[i - 1];
        ll time = ((target - a[i - 1]) * (b[i] - b[i - 1])) / (a[i] - a[i - 1]);
        ans.push_back(res + time);
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}