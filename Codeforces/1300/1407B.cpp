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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

set<int> factors(int x)
{
    set<int> st;
    for (int i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0)
        {
            if (x / i != i)
                st.insert(x / i);
            st.insert(i);
        }
    return st;
}

vec solve()
{
    int n = II;
    vec v(n);
    iv(v);

    int a = *max_element(all(v));
    vv adj(a + 1);
    for (int i = 0; i < n; i++)
        for (int j = 1, sq = sqrt(v[i]); j <= sq; j++)
            if (v[i] % j == 0)
            {
                if (v[i] / j != j)
                    adj[v[i] / j].push_back(i);
                adj[j].push_back(i);
            }
    
    vec ans, vis(n, 0);
    function<void(int, int)> dfs = [&](int u, int i) {
        ans.push_back(v[i]);
        vis[i] = 1;
        auto st = factors(u);
        for (auto it = st.rbegin(); it != st.rend(); it++)
            for (int j : adj[*it])
                if (!vis[j]) {
                    dfs(*it, j);
                    return;
                }
    };
    
    int i = find(all(v), a) - v.begin();
    dfs(a, i);
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}