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
    int n = II, k = II, len = k * 2;
    vec mp(n + 1, 0);
    for (int i = 0; i < n; i++)
        mp[II]++;
    for (int i = 0; i < n; i++) II;
    
    for (int i = 1; i <= n && len; i++)
        if (mp[i] == 2) {
            pf(i) << i << " ";
            len -= 2;
            mp[i] = -2;
        }

    int cnt = len;
    for (int i = 1; i <= n && len; i++)
        if (mp[i] == 1) {
            pf(i);
            len--;
            mp[i] = -1;
        }
    br;

    for (int i = 1; i <= n; i++)
        if (mp[i] == -1)
            pf(i);
    
    int rem = k * 2 - cnt;
    for (int i = 1; i <= n && rem; i++)
        if (mp[i] == 0) {
            pf(i) << i << " ";
            rem -= 2;
        }
    br;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}