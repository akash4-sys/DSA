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
    int n = II + 1, m = n - 2, idx = 0;
    vector<int> col(n), start(n), end(n), ans(n);
    for (int i = 1; i < n; i++)
        cin >> col[i];
    
    vector<vector<int>> g(n);
    while (m--) {
        int u = II, v = II;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    BIT bit(n);
    auto dfs = [&](auto &&dfs, int u, int par) -> void {
        start[u] = idx;
        for (int v : g[u])
            if (v != par)
                dfs(dfs, v, u);
        end[idx] = u;
        idx++;
    };
    dfs(dfs, 1, 0);

    map<int, int> last;
    for (int i = 0; i < n; i++) {
        if (last.count(col[end[i]]))
            bit.update(last[col[end[i]]], -1);
        last[col[end[i]]] = i;
        bit.update(i, 1);
        ans[end[i]] = bit.query(i) - bit.query(start[end[i]] - 1);
    }

    for (int i = 1; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}