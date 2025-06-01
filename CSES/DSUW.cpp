#include <bits/stdc++.h>
using namespace std;

class DSUW
{
    vector<int> par;
public:
    DSUW(int n) : par(n, -1) {}

    int findPar(int u) {
        return par[u] < 0 ? u : par[u] = findPar(par[u]);
    }

    int size(int u) {
        return -par[findPar(u)];
    }

    bool Union(int u, int v)
    {
        u = findPar(u), v = findPar(v);
        if (u == v)
            return 0;
        if (par[u] > par[v])
            swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return 1;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    DSUW dsu(n);
    int components = n, mx = 1;

    while (m-- && components)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        components -= dsu.Union(u, v);
        mx = max(mx, dsu.size(u));
        cout << components << " " << mx << "\n";
    }
    return 0;
}