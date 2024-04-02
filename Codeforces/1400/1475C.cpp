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

ll solve()
{
    int a = II, b = II, k = II;
    vector<int> cntb(a + 1, 0), cntg(b + 1, 0), boy(k), girl(k);
    for (int i = 0; i < k; i++)
        boy[i] = II, cntb[boy[i]]++;
    for (int i = 0; i < k; i++)
        girl[i] = II, cntg[girl[i]]++;
    
    ll ans = 0;
    for (int i = 0; i < k; i++)
        ans += (k - cntb[boy[i]] - cntg[girl[i]] + 1);
    return ans / 2;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}