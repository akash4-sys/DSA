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

int solve()
{
    int n = II;
    vec v(n);
    iv(v);

    unordered_map<int, int> mp;
    for (int x : v)
    {
        for (int i = 2; i * i <= x; i++)
            while (x % i == 0)
                x /= i, mp[i]++;
        mp[x] += (x != 1);
    }

    int ans = 0, r = 0;
    for (auto [x, c] : mp) {
        ans += (c / 2);
        r += (c % 2);
    }
    ans += (r / 3);
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