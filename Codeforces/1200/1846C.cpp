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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    ll n = LL, m = LL, h = LL;
    vv v;
    for (int i = 0; i < n; i++)
    {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int j = 0; j < m; j++)
            pq.push(LL);
        
        ll time = 0, penalty = 0, pt = 0;
        while (!pq.empty() && time < h)
        {
            ll x = pq.top();
            pq.pop();
            if (time + x > h)
                break;
            time += x;
            penalty += time;
            pt++;
        }
        v.push_back({pt, penalty, i});
    }

    sort(v.begin(), v.end(), [&](const auto &a, const auto &b) {
        if (a[0] == b[0] && a[1] == b[1])
            return a[2] < b[2];
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    });

    for (ll i = 0; i < v.size(); i++)
        if (!v[i][2])
            return i + 1;
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