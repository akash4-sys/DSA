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

ll solve()
{
    ll n = LL, m = LL, ans = 0;
    vv v(n, vec(m));
    for (auto &r : v)
        iv(r);

    for (int j = 0; j < m; j++)
    {
        vec c;
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += v[i][j], c.push_back(v[i][j]);
        
        sort(all(c));
        sum -= c[0];
        for (int i = 1; i < n; i++)
            ans += abs(sum - (c[i - 1] * (n - i))), sum -= c[i];
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