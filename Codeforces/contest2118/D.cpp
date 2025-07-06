#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II, k = II;
    vec p(n), d(n);
    iv(p); iv(d);

    vector<int> next(n * 2, -1), out(n * 2, 0);
    map<ll, int> mp;
    for (int i = n - 1; i >= 0; i--) {
        ll v = (d[i] - p[i] % k + k) % k;
        if (mp.count(v))
            next[n + i] = mp[v];
        mp[v] = i;
    }
    mp.clear();

    for (int i = 0; i < n; i++) {
        ll v = (d[i] + p[i]) % k;
        if (mp.count(v))
            next[i] = mp[v] + n;
        mp[v] = i;
    }

    vector<vector<int>> g(n * 2);
    queue<int> q;
    for (int i = 0; i < n * 2; i++)
        if (next[i] == -1)
            out[i] = 1, q.push(i);
        else
            g[next[i]].push_back(i);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u])
            out[v] = 1, q.push(v);
    }

    map<ll, vector<pair<ll, int>>> grp;
    for (int i = 0; i < n; i++) {
        ll v = (p[i] - d[i] + k) % k;
        grp[v].emplace_back(p[i], i);
    }

    int qrs = II;
    while (qrs--) {
        ll a = LL;
        if (!grp.count(a % k)) {
            pyn(1);
            continue;
        }

        auto &v = grp[a % k];
        auto it = lower_bound(all(v), make_pair(a, 0));
        if (it == v.end()) {
            pyn(1);
            continue;
        }
        pyn(out[it->second]);
    }
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}