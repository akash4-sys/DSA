#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, k = II, z = II, ans = 0;
    vec a(n);
    iv(a);
    for (int t = 0; t <= z; t++)
    {
        int sum = 0, mx = 0;
        for (int i = 0; i <= k - (t * 2); i++) {
            if (i < n - 1)
                mx = max(mx, a[i] + a[i + 1]);
            sum += a[i];
        }
        ans = max(ans, mx * t + sum);
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}