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

void solve()
{
    int n = II;
    vec nums(n), v(n);
    iv(nums);
    string s = SS;
    int q = II, x = 0, ones = 0, zero = 0;

    for (int i = 0; i < n; i++)
    {
        v[i] = (x ^= nums[i]);
        ones = s[i] == '1' ? ones ^ nums[i] : ones;
        zero = s[i] == '0' ? zero ^ nums[i] : zero;
    }

    for (int i = 0; i < q; i++)
    {
        int t = II;
        if (t == 1)
        {
            int l = II - 1, r = II - 1;
            int sub = v[r] ^ (l >= 1 ? v[l - 1] : 0);
            ones ^= sub;
            zero ^= sub;
        }
        else
        {
            int grp = II, calc = grp ? ones : zero;
            pf(calc);
        }
    }
    br;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}