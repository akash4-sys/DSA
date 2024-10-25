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

void solve()
{
    int n = II;
    vector<set<int>> g(n);
    for (int i = 0; i < n; i++) {
        int u = II - 1;
        g[u].insert(i);
        g[i].insert(u);
    }

    vector<int> col(n, 0);
    auto dfs = [&](auto &&dfs, int u, int c) -> void {
        col[u] = c;
        for (int v : g[u])
            if (!col[v])
                dfs(dfs, v, c);
    };

    int c = 0;
    for (int i = 0; i < n; i++)
        if (!col[i])
            c++, dfs(dfs, i, c);
    
    set<int> st;
    for (int i = 0; i < n; i++)
        if (g[i].size() != 2)
            st.insert(col[i]);
    
    int x = c + (st.size() ? 1 - st.size() : 0);
    cout << x << " " << c << "\n";
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}