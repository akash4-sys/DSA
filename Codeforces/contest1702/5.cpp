#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

class DSU
{
    vector<int> parent;
public:
    DSU(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int u) {
        return parent[u] == u ? u : parent[u] = findParent(parent[u]);
    }

    bool Union(int u, int v)
    {
        int uPar = findParent(u), vPar = findParent(v);
        if (uPar == vPar)
            return 1;
        parent[uPar] = vPar;
        return 0;
    }
};

bool solve()
{
    int n = II;
    vector<int> cnt(n);
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        int a = II - 1, b = II - 1;
        v[i] = {a, b};
        cnt[a]++, cnt[b]++;
    }

    for (int i = 0; i < n; i++)
        if (cnt[i] != 2)
            return 0;
    
    DSU dsu(n * 2 + 1);
    for (auto &p : v)
        dsu.Union(p[0], p[1] + n), dsu.Union(p[0] + n, p[1]);
    
    for (int i = 0; i < n; i++)
        if (dsu.findParent(i) == dsu.findParent(i + n))
            return 0;
    return 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}