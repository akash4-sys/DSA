#include <bits/stdc++.h>
using namespace std;

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

vv dp;

int rec(string &s, string &a, string &b, int i, int j) {
    if (dp[i + 1][j + 1] != -1)
        return dp[i + 1][j + 1];

    int res = 0;
    if (i + 1 < a.size())
        res = rec(s, a, b, i + 1, j) + (s[i + j + 2] == a[i + 1]);
    if (j + 1 < b.size())
        res = max(res, rec(s, a, b, i, j + 1) + (s[i + j + 2] == b[j + 1]));
    return dp[i + 1][j + 1] = res;
}

int solve()
{
    string a = SS, b = SS, s = SS;
    dp = vv(a.size() + 1, vec(b.size() + 1, -1));
    return s.size() - rec(s, a, b, -1, -1);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}