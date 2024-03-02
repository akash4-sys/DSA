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

ll maxsum(vec &v)
{
    ll sum = 0, neg = LLONG_MIN;
    for (ll a : v) {
        sum += (a > 0 ? a : 0);
        neg = a <= 0 ? max(neg, a) : neg;
    }
    return sum ? sum : neg;
}

ll solve()
{
    int n = II;
    vec even, odd;
    for (int i = 0; i < n; i++)
        if (i % 2)
            odd.push_back(LL);
        else
            even.push_back(LL);
    return max(maxsum(odd), maxsum(even));
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}