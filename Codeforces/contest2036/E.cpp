

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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vv transpose(vv &m)
{
    vv t(m[0].size(), vector<ll>(m.size(), 0));
    for (int i = 0; i < m.size(); i++)
        for (int j = 0; j < m[0].size(); j++)
            t[j][i] = m[i][j];
    return t;
}

int solve(vv &v, int n, int m)
{
    int k = II;
    map<int, int> low, high;
    for (int i = 0; i < k; i++) {
        int r = II - 1;
        char c;
        cin >> c;
        int val = II;
        if (c == '<') {
            if (!low.count(r))
                low[r] = val;
            else
                low[r] = min(low[r], val);
        }
        if (c == '>') {
            if (!high.count(r))
                high[r] = val;
            else
                high[r] = max(high[r], val);
        }
    }

    int l = 0, r = m;
    for (auto &it : high) {
        int j = upper_bound(all(v[it.first]), it.second) - v[it.first].begin();
        l = max(l, j);
    }

    for (auto &it : low) {
        int j = lower_bound(all(v[it.first]), it.second) - v[it.first].begin() - 1;
        r = min(r, j);
    }

    if (l > r || l == m)
        return -1;
    return l + 1;
}

int main()
{
    fast;
    int n = II, m = II, q = II;
    vv v(n, vec(m, 0));
    for (auto &r : v)
        iv(r);
    
    for (int j = 0; j < m; j++)
        for (int i = 1; i < n; i++)
            v[i][j] |= v[i - 1][j];
    
    v = transpose(v);
    swap(n, m);

    while (q--)
        pl(solve(v, n, m));
    return 0;
}