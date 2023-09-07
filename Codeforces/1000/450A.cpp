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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, m = II, last = -1;
    deque<pair<int, int>> dq;
    for (int i = 1; i <= n; i++)
        dq.push_back({II, i});
    
    while (!dq.empty())
    {
        auto [c, i] = dq.front();
        last = i;
        dq.pop_front();
        if (c - m > 0)
            dq.push_back({c - m, i});
    }
    return last;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}