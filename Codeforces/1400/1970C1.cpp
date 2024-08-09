#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl

bool solve()
{
    int n = II, t = II, ans = 0;
    vv g(n);
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int st = II - 1;

    function<int(int, int)> dfs = [&](int u, int par) -> int {
        int res = 1;
        for (int &v : g[u])
            if (v != par)
                res += dfs(v, u);
        return res;
    };

    for (int &v : g[st])
        ans |= (dfs(v, st) % 2);
    return ans;
}

int main()
{
    fast;
    pl((solve() ? "Ron" : "Hermione"));
    return 0;
}