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

int solve()
{
    int n = II;
    double m = n / 2.0;
    string s = SS;
    s = "a" + s;
    int ones = count(all(s), '1'), zeros = 0, d = n, idx = -1;
    if (ones >= ceil(n / 2.0))
        idx = 0, d = n / 2;

    for (int i = 1; i <= n; i++)
    {
        zeros += s[i] == '0';
        ones -= s[i] == '1';
        ll r = n - i, l = i;
        if (zeros >= ceil(l / 2.0) && ones >= ceil(r / 2.0))
        {
            ll dist = abs(m - i);
            if (dist < d)
                idx = i, d = dist;
        }
    }
    return idx;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}