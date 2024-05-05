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

int solve()
{
    int n = II, k = II, ans = 0;
    string s = SS;
    for (int i = 0; i < k; i++)
    {
        int ch[26] = {0}, tot = 0, x = 0;
        for (int l = i, r = k - i - 1; l < n; l += k, r += k)
            ch[s[l] - 'a']++, ch[s[r] - 'a']++;
        
        for (int f : ch)
            tot += f, x = max(x, f);
        ans += (tot - x);
    }
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