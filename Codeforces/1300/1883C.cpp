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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int check(vec &v)
{
    int two = 0, odd = 0;
    for (int x : v)
    {
        if (x % 2 == 0)
        {
            while (x % 2 == 0)
                x /= 2, two++;
        }
        else
            odd++;
    }

    if (two >= 2)
        return 0;
    if (two == 1 && odd >= 1)
        return 1;
    return 2;
}

int solve()
{
    int n = II, k = II, ans = INT_MAX;
    vec v(n);
    iv(v);

    for (int x : v)
    {
        int r = (x / k) + 1;
        if (x % k == 0)
            return 0;
        if (x < k)
            ans = min(ans, k - x);
        else
            ans = min(ans, (k * r) - x);
    }

    if (k == 4)
        ans = min(ans, check(v));
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