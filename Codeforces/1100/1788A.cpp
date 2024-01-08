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
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, two = 0, pf_two = 0;
    vec v(n);
    for (int i = 0; i < n; i++) {
        v[i] = II;
        two += v[i] == 2;
    }
    
    pf_two += v[0] == 2, two -= v[0] == 2;
    for (int i = 1; i < n; i++) {
        if (two == pf_two)
            return i;
        pf_two += v[i] == 2;
        two -= v[i] == 2;
    }
    return -1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}