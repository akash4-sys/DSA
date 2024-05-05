#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
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

// you can delete from anywhere, so that's what is wrong

int solve()
{
    int n = II, ans = -1;
    vec v(n);
    iv(v);
    if (count(all(v), v[0]) == n)
        return -1;
    
    for (int i = 1; i < n; i++)
        if (v[i] != v[i - 1]) {
            ans = i;
            break;
        }
    
    for (int i = n - 2; i >= 0; i--)
        if (v[i] != v[i + 1]) {
            ans = min(ans, n - i - 1);
            break;
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