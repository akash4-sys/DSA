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

bool solve()
{
    int n = II;
    vec v(n);
    iv(v);
    sort(all(v));
    ll sum_red = 0, sum_blue = v[0];
    for (int i = 1, j = n - 1; i < j; i++, j--)
    {
        sum_blue += v[i];
        sum_red += v[j];
        if (sum_red > sum_blue)
            return 1;
    }
    return 0;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}