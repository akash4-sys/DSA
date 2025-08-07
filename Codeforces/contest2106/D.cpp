#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, m = II, ans = INT_MAX;
    vec a(n), b(m), pre(m), sf(m);
    iv(a); iv(b);
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n && a[j] < b[i])
            j++;
        pre[i] = j++;
    }

    if (pre.back() < n)
        return 0;

    for (int i = m - 1, j = n - 1; i >= 0; i--) {
        while (j >= 0 && a[j] < b[i])
            j--;
        sf[i] = j--;
    }

    for (int i = 0; i < m; i++) {
        int p = i == 0 ? -1 : pre[i - 1];
        int nx = i + 1 == m ? n : sf[i + 1];
        if (p < nx)
            ans = min(ans, b[i]);
    }
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}