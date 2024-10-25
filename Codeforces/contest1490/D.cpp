#include <bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ int a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

class SparseTable
{
    int n, LOG = 8;
    vector<vector<int>> m;

public:
    SparseTable(vector<int> &v)
    {
        n = v.size();
        m = vector<vector<int>>(n + 1, vector<int>(LOG, 0));

        for (int i = 0; i < n; i++)
            m[i][0] = v[i];
        
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i + (1 << j) - 1 < n; i++)
                m[i][j] = max(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
    }

    int query(int l, int r)
    {
        int k = 0, len = r - l + 1;
        while ((1 << (k + 1)) <= len)
            k++;
        return max(m[l][k], m[r - (1 << k) + 1][k]);
    }
};

vec solve()
{
    int n = II;
    vec v(n), ans(n), idx(n + 1);
    iv(v);
    for (int i = 0; i < n; i++)
        idx[v[i]] = i;
    
    SparseTable mat(v);
    function<void(int, int, int)> dfs = [&](int l, int r, int d) -> void {
        if (l > r) return;

        int x = mat.query(l, r);
        ans[idx[x]] = d;
        dfs(l, idx[x] - 1, d + 1);
        dfs(idx[x] + 1, r, d + 1);
    };
    dfs(0, n - 1, 0);
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}