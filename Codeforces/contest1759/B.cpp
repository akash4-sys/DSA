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

string solve()
{
    ll n = II, sum = LL, a, k = 0;
    for (int i = 0; i < n; i++) {
        a = II;
        sum += a;
        k = max(k, a);
    }

    for (int i = 1, total = 0; i < 100; i++)
    {
        total += i;
        if (total == sum && k <= i)
            return "Yes";
    }
    return "No";
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        pl(solve());
    return 0;
}