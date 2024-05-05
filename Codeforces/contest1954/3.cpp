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

void solve()
{
    string a = SS, b = SS;
    int i = 0;
    while (i < a.size() && a[i] == b[i]) i++;
    if (i < a.size() && a[i] < b[i])
        swap(a[i], b[i]);
    for (i++; i < a.size(); i++)
        if (a[i] > b[i])
            swap(a[i], b[i]);
    
    pl(a);
    pl(b);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}