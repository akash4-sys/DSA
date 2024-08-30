#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    int n = II, k = II;
    vec ans(n, 0), a;
    vv idx(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a = II;
        idx[a].push_back(i);
        if (idx[a].size() == k)
            for (int j = 0; j < k; j++)
                ans[idx[a][j]] = j + 1;
    }

    for (int i = 1; i <= n; i++)
        if (idx[i].size() < k && idx[i].size() > 0)
            for (auto &id : idx[i])
                a.push_back(id);
    
    for (int i = 0, m = a.size(), c = 0; i < m - (m % k); i++)
        ans[a[i]] = c + 1, c = (c + 1) % k;
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}