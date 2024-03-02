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
#define pf(x) cout << x << "\n"
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); }}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vector<string> solve()
{
    int n = II, q = II;
    vec cnt(n + 1, 0), pfsum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ll a = LL;
        cnt[i] = cnt[i - 1] + (a == 1);
        pfsum[i] = pfsum[i - 1] + a;
    }
    
    vector<string> ans;
    while (q--)
    {
        int l = II, r = II, m = r - l + 1;
        ll sum = pfsum[r] - pfsum[l - 1] - m;
        ll ones = cnt[r] - cnt[l - 1];
        if (sum < ones || m == 1)
            ans.push_back("NO");
        else
            ans.push_back("YES");
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}