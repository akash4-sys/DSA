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
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

bool solve()
{
    int n = II, k = II, cnt = 0;
    vv v(k, vec(n)), g(n);
    vec deg(n, 0);
    for (auto &a : v) {
        for (int i = 0; i < n; i++)
            a[i] = II - 1;
        for (int i = 1; i < n - 1; i++) {
            g[a[i]].push_back(a[i + 1]);
            deg[a[i + 1]]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!deg[i])
            q.push(i);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int c : g[u])
            if (--deg[c] == 0)
                q.push(c);
    }
    return cnt == n;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}