#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define iv(v) { for(auto &x : v) cin >> x; }

int dp[200001];

bool rec(vec &v, vv &idx, int i)
{
    if (i == v.size())
        return 1;
    if (dp[i] != -1)
        return dp[i];
    
    int res = 0;
    if (i + v[i] < v.size())
        res |= rec(v, idx, i + v[i] + 1);
    for (auto &j : idx[i])
        res |= rec(v, idx, j + 1);
    return dp[i] = res;
}

bool solve()
{
    int n = II;
    vec v(n);
    iv(v);
    vv idx(n);
    for (int i = n - 1; i >= 0; i--)
        if (i >= v[i])
            idx[i - v[i]].push_back(i);

    memset(dp, -1, sizeof(dp));
    return rec(v, idx, 0);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}