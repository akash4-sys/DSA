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

vec solve()
{
    int n = II, d = II, k = II;
    vec st(n + 1, 0), end(n + 1, 0);
    for (int i = 0; i < k; i++)
        st[II]++, end[II]++;
    
    for (int i = 1; i <= n; i++)
        st[i] += st[i - 1], end[i] += end[i - 1];
    
    int mx = 0, b = 0, m = 0, mn = INT_MAX;
    for (int i = d; i <= n; i++)
    {
        int cnt = st[i] - end[i - d];
        if (cnt > mx)
            mx = cnt, b = i - d + 1;
        if (cnt < mn)
            mn = cnt, m = i - d + 1;
    }
    return {b, m};
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}