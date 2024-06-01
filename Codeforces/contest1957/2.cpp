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
    int n = II;
    vec v(n), div(n, 0);
    iv(v);

    sort(all(v));
    for (int i = 0; i < n; i++)
        div[i] = (v[i] % v[0] == 0);
    
    if (accumulate(all(div), 0) == n)
        return 1;
    
    int i = 0;
    while (i < n && div[i])
        i++;
    
    for (int j = i; j < n; j++)
        if (!div[j])
            div[j] = (v[j] % v[i] == 0);
    return (accumulate(all(div), 0) == n);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}