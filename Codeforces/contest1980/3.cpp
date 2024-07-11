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

bool solve()
{
    int n = II;
    vec a(n), b(n);
    iv(a);
    iv(b);

    int m = II, useless = 0;
    vec d(m);
    iv(d);
    map<int, int> mpd, mpb;
    for (auto &x : d)
        mpd[x]++;
    for (auto &x : b)
        mpb[x]++;
    
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            if (!mpd.count(b[i]) || mpd[b[i]] == 0)
                return 0;
            mpd[b[i]]--;
        }
    
    for (int i = 0; i < m; i++) {
        if (mpd[d[i]] > 0)
            useless++;
        if (mpd[d[i]] == 0 || mpb.count(d[i]))
            useless = 0;
    }
    return !useless;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}