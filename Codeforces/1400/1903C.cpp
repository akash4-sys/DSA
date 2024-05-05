
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

ll rec(vec &v, int i, int k)
{
    if (i == v.size())
        return 0;
    
    ll res = INT_MIN, sum = 0;
    for (int j = i; j < v.size(); j++) {
        sum += v[j];
        res = max(res, rec(v, j + 1, k + 1) + (sum * k));
    }
    return res;
}

ll solve()
{
    int n = II;
    vec v(n);
    iv(v);
    return rec(v, 0, 1);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}