#include <bits/stdc++.h>
using namespace std;

#define vv vector<vector<int>>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }

class TreeAncestor
{
    int n, maxDepth;
    vector<vector<int>> ancestor;
public:
    TreeAncestor(int n, vector<int> &par)
    {
        this->n = n;
        maxDepth = log2(n) + 1;
        ancestor = vector(n, vector<int>(maxDepth, -1));

        for (int i = 0; i < n; i++)
            ancestor[i][0] = par[i];

        for (int j = 1; j < maxDepth; j++)
            for (int i = 0; i < n; i++)
                if (ancestor[i][j - 1] != -1)
                    ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
    }

    pair<int, int> kthAncestor(int node, int k)
    {
        int dist = 0;
        for (int i = 0; i < maxDepth; i++)
            if (k & (1 << i)) {
                node = ancestor[node][i];
                if (node == -1)
                    break;
                dist |= (1 << i);
            }
        return {node, dist};
    }
};

void bfs(vector<vector<int>> &dp, vector<int> &leaf, vector<int> &par)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < leaf.size(); i++)
        if (leaf[i])
            q.push({i, 0});
    
    while (!q.empty())
    {
        auto [u, len] = q.front();
        q.pop();
        if (len >= dp[u][0])
            dp[u][1] = dp[u][0], dp[u][0] = len;
        else if (len > dp[u][1])
            dp[u][1] = len;
        if (par[u] != -1)
            q.push({par[u], len + 1});
    }
}

vector<int> solve()
{
    int n = II;
    vector<int> par(n, -1), leaf(n, 1);
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1;
        // g[v].push_back(u);
        par[v] = u;
        leaf[u] = 0;
    }

    TreeAncestor tree(n, par);
    vector<vector<int>> dp(n, vector<int>(2, 0));
    bfs(dp, leaf, par);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}