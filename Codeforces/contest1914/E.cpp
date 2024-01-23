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
    ll n = II, sum = 0;
    vec a(n), b(n), id(n);
    iv(a);
    iv(b);
    iota(all(id), 0);
    sort(all(id), [&](int i, int j){
        return a[i] + b[i] > a[j] + b[j];
    });
    
    for (int i = 0; i < n; i++)
        sum += i % 2 ? -b[id[i]] + 1 : a[id[i]] - 1;
    return sum;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}