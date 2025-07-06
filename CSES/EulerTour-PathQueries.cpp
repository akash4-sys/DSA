#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })

class BIT 
{
    int n;
    vector<long long> bit;
public:
    BIT(int _n): n(_n + 1), bit(_n + 1, 0) {}

    long long query(int i) {
        long long sum = 0;
        for (++i; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    void update(int i, int val) {
        for (++i; i < n; i += i & (-i))
            bit[i] += val;
    }
};

int main()
{
    int n = II, q = II, m = n - 1, timer = 0;
    vector<int> a(n), start(n), end(n);
    for (int &c : a)
        c = II;
    
    vector<vector<int>> g(n);
    while (m--) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    BIT bit(n + 1);
    auto dfs = [&](auto &&dfs, int u, int par) -> void {
        start[u] = timer++;
        for (int v : g[u])
            if (v != par)
                dfs(dfs, v, u);
        end[u] = timer - 1;
        bit.update(start[u], a[u]);
        bit.update(end[u] + 1, -a[u]);
    };
    dfs(dfs, 0, -1);
    
    while (q--)
    {
        int type = II, u = II - 1;
        if (type == 1) {
            long long x = II;
            bit.update(start[u], x - a[u]);
            bit.update(end[u] + 1, a[u] - x);
            a[u] = x;
        }
        else
            cout << bit.query(start[u]) << "\n";
    }
    return 0;
}