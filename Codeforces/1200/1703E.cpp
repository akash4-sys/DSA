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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }
 
int solve()
{
    int n = II, ans = 0;
    vv v(n, vec(n, 0));
    for (auto &r : v)
        for (int &a : r)
        {
            char c;
            cin >> c;
            a = c - '0';
        }
 
    for (int i = 0; i < n / 2; i++)
    {
        int uli = i, ulj = i, uri = i, urj = n - i - 1;
        int lli = n - i - 1, llj = i, lri = n - i - 1, lrj = n - i - 1;
        int d = urj - ulj;
        while (d--)
        {
            int one = v[uli][ulj] + v[uri][urj] + v[lli][llj] + v[lri][lrj];
            ans += min(one, 4 - one);
            ulj++, uri++;
            lli--, lrj--;
        }
    }
    return ans;
}
 
int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}
 