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

string solve()
{
    int n = II, k = II, cnt = 0;
    vv v(n, vec(n, 0));
    for (auto &r : v)
        iv(r);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cnt += v[i][j] != v[n - i - 1][n - j - 1];
    
    cnt /= 2;
    if (cnt > k)
        return "NO";
    k -= cnt;
    if (n % 2)
        return "YES";
    if (k % 2)
        return "NO";
    return "YES";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}