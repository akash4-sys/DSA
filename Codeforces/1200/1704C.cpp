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
    ll n = LL, m = LL, cnt = 0, day = 0, rem = 0;
    vec a(m), v;
    iv(a);
    sort(all(a));

    for (int i = 1; i < m; i++)
        v.push_back(a[i] - a[i - 1] - 1);
    v.push_back(n - a.back() + a[0] - 1);
    sort(all(v), greater<int>());

    for (int i = 0; i < v.size() && rem >= 0; i++, day += 2)
    {
        rem = v[i] - (day * 2) - 1;
        cnt += rem == 0 ? 1 : max(rem, 0LL);
    }
    return n - cnt;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}