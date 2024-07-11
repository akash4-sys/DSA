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
    ll h = LL, n = LL;
    vec a(n), c(n);
    iv(a);
    iv(c);

    priority_queue<vec, vector<vec>, greater<vec>> pq;
    for (int i = 0; i < n; i++) {
        h -= a[i];
        pq.push({c[i] + 1, a[i], c[i]});
    }

    if (h <= 0)
        return 1;

    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        ll onturn = v[0], atk = v[1], cd = v[2];
        h -= atk;
        if (h <= 0)
            return onturn;
        pq.push({onturn + cd, atk, cd});
    }
    return -1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}