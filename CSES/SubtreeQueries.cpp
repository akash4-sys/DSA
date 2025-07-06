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

    long long getSum(int i) {
        long long sum = 0;
        for (++i; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    void add(int i, int val) {
        for (++i; i < n; i += i & (-i))
            bit[i] += val;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), post, treeSize(n), idx(n);
    for (int &c : a)
        c = II;
    
    vector<vector<int>> g(n);
    for (int m = n - 1; m; m--)  {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    BIT bit(n);
    auto dfs = [&](auto &&dfs, int u, int par) -> void {
        treeSize[u]++;
        for (int v : g[u])
            if (v != par) {
                dfs(dfs, v, u);
                treeSize[u] += treeSize[v];
            }
        post.push_back(u);
        idx[u] = post.size() - 1;
        bit.add(idx[u], a[post[idx[u]]]);
    };
    dfs(dfs, 0, -1);


    while (q--)
    {
        int type = II, u = II - 1, i = idx[u];
        if (type == 1) {
            long long x = II;
            bit.add(i, x - a[u]);
            a[u] = x;
        }
        else
            cout << bit.getSum(i) - bit.getSum(i - treeSize[u]) << "\n";
    }
    return 0;
}