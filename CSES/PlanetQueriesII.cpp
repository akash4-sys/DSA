#include <bits/stdc++.h>
using namespace std;

// Distance between any two nodes in a tree with only 1 child and atmost 1 cycle
 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

class TreeAncestor
{
    int n, maxDepth = 30;
    vector<vector<int>> ancestor;
public:
    TreeAncestor(int n, vector<int> &par)
    {
        this->n = n;
        ancestor = vector(n, vector<int>(maxDepth, -1));
        for (int i = 0; i < n; i++)
            ancestor[i][0] = par[i];
        for (int j = 1; j < maxDepth; j++)
            for (int i = 0; i < n; i++)
                if (ancestor[i][j - 1] != -1)
                    ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
    }

    int kthNode(int node, int k)
    {
        if (k < 0)
            return -1;
        for (int i = 0; i < maxDepth; i++)
            if (k & (1 << i)) {
                node = ancestor[node][i];
                if (node == -1)
                    return -1;
            }
        return node;
    }
};

int main()
{
    fast;
    int n = II, q = II;
    vector<int> v(n), len(n, 0), vis(n, 0);
    for (int i = 0; i < n; i++)
        v[i] = II - 1;
    
    auto dfs = [&](auto &&dfs, int u){
        if (vis[u])
            return;
        vis[u] = 1;
        dfs(dfs, v[u]);
        len[u] = len[v[u]] + 1;
    };

    for (int i = 0; i < n; i++)
        dfs(dfs, i);
    
    TreeAncestor t(n, v);
    while (q--) 
    {
        int a = II - 1, b = II - 1, u = t.kthNode(a, len[a]);
        if (t.kthNode(a, len[a] - len[b]) == b)
            cout << len[a] - len[b] << "\n";
        else if (t.kthNode(u, len[u] - len[b]) == b)
            cout << len[a] + len[u] - len[b] << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}