#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II;
    vec v(n);
    iv(v);
    int q = II;
    vector<pair<int, int>> vp;
    for (int i = 0; i < q; i++)
        vp.push_back({II, II});
    
    vv dp(n + 1, vector<int>(32, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 32; j++)
            dp[i + 1][j] = dp[i][j] + ((v[i] & (1 << j)) != 0);
    
    for (auto [l, k] : vp)
    {
        if (v[l - 1] < k) {
            pf(-1);
            continue;
        }

        int low = l, high = n, ans = low;
        while (low <= high)
        {
            int mid = (low + high) / 2, num = 0;
            for (int j = 0; j < 32; j++)
                if (dp[mid][j] - dp[l - 1][j] == mid - l + 1)
                    num += (1 << j);
            
            if (num >= k)
                low = mid + 1, ans = mid;
            else
                high = mid - 1;
        }
        pf(ans);
    }
    br;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}