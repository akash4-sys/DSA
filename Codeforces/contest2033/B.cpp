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

ll solve()
{
    int n = II;
    vector<vector<int>> v(n, vec(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int a = II;
            v[i][j] = a < 0 ? abs(a) : 0;
        }
    
    ll ans = 0;
    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int i = 0, k = j; i < n && k < n; i++, k++)
            cnt = max(cnt, v[i][k]);
        ans += cnt;
    }

    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int j = 0, k = i; j < n && k < n; j++, k++)
            cnt = max(cnt, v[k][j]);
        ans += cnt;
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