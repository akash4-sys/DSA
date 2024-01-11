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

ll solve()
{
    ll n = LL;
    string s = to_string(n);

    ll m = s.size(), ans = 100;
    for (int i = s.size() - 1; i >= 0; i--)
        if (s[i] == '0' || s[i] == '5')
            for (int j = i - 1; j >= 0; j--)
            {
                bool cond1 = s[i] == '0' && (s[j] == '0' || s[j] == '5');
                bool cond2 = s[i] == '5' && (s[j] == '2' || s[j] == '7');
                if (cond1 || cond2) {
                    ans = min(ans, (m - i - 1) + (i - j - 1));
                    break;
                }
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