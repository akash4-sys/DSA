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
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(vv) { for(auto &v : vv) pv(v), br; }
#define iv(v, n) { for(int i = 0; i < n; i++) cin >> v[i]; }

int solve()
{
    ll n = LL, m = LL, sum = -m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x = II, y = II;
        sum += (ll)x;
        v[i] = x - y;
    }

    sort(all(v), greater<int>());
    int i = 0;
    for (; sum > 0 && i < n; i++)
        sum -= v[i];
    
    if (sum > 0 && i == n)
        return -1;
    return i;
}

int main()
{
    fast;
    pf(solve());
    return 0;
}