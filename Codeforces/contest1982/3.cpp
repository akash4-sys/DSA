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
#define pl(x) cout << x << endl
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, l = II, r = II, i = 0, wins = 0;
    vec v(n), pf;
    iv(v);
    for (auto &a : v)
        pf.push_back((pf.size() ? pf.back() : 0LL) + a);

    for (; i < n; i++)
    {
        if (v[i] >= l && v[i] <= r) {
            wins++;
            continue;
        }
        if (v[i] > r)
            continue;

        ll d = l - v[i];
        int j = lower_bound(all(pf), pf[i] + d) - pf.begin();
        if (j != n) {
            ll sum = pf[j] - (i >= 1 ? pf[i - 1] : 0);
            if (sum >= l && sum <= r)
                wins++, i = j;
        }
    }
    return wins;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}