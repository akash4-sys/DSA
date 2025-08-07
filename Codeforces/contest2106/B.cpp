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
    int n = II, x = II;
    vec ans(n, 0);
    for (int i = 0; i < x; i++)
        ans[i] = i;
    for (int i = x; i < n; i++)
        ans[i] = i + 1;
    if (ans.back() >= n)
        ans.back() = x;
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}