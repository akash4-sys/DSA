#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })

string code;

int dfs(vector<vector<int>> &g, int u)
{
    int res = 0, p = 0, s = 0;
    for (int v : g[u])
        res += dfs(g, v), p += code[v] == 'P', s += code[v] == 'S';
    
    if (code[u] != 'C')
        return res + (code[u] == 'S' ? p : s);

    if (p > s)
        code[u] = 'P', res += s;
    else if (s > p)
        code[u] = 'S', res += p;
    else
        res += p;
    return res;
}

int solve()
{
    int n = II;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++)
        g[II - 1].push_back(i);
    code = SS;
    return dfs(g, 0);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}