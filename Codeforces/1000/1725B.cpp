

#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
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
    ll n = LL, d = LL, ans = 0, r = n;
    vec v(n);
    iv(v);
    sort(all(v), greater<int>());
    for (int i = 0; i < n; i++)
    {
        int players_needed = ceil((d + 1.0) / v[i]);
        if (players_needed > r)
            break;
        r -= players_needed;
        ans++;
    }
    return ans;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}