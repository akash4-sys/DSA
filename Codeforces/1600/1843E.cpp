#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }

int solve()
{
    int n = II, m = II;
    vector<vector<int>> seg(m);
    for (int i = 0; i < m; i++)
        seg[i] = {II, II};
    
    int q = II;
    vector<int> qrs(q);
    for (auto &x : qrs)
        x = II;
    
    int l = 0, r = q, res = q + 1;
    while (l <= r)
    {
        int k = (l + r) / 2, f = 0;
        vector<int> a(n + 1, 0);
        for (int i = 0; i < k; i++)
            a[qrs[i]] = 1;
        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        
        for (auto &s : seg)
            if (a[s[1]] - a[s[0] - 1] > (s[1] - s[0] + 1) / 2) {
                f = 1;
                break;
            }
        
        if (f)
            r = k - 1, res = min(res, k);
        else
            l = k + 1;
    }
    return res == q + 1 ? -1 : res;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}