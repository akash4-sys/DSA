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
    ll n = LL, maxsum = LLONG_MIN, sum = 0, ans = LLONG_MIN;
    vec v(n);
    iv(v);
    for (int i = 0; i < n; i++)
    {
        maxsum = max(maxsum, sum + v[i]);
        sum = max(sum + v[i], 0LL);
        ans = max(ans, maxsum);
        if (i + 1 < n && abs(v[i]) % 2 == abs(v[i + 1]) % 2)
            maxsum = LLONG_MIN, sum = 0;
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