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
    int n = II;
    char c;
    cin >> c;
    string s = SS;
    if (c == 'g')
        return 0;

    vec gidx;
    for (int i = 0; i < n; i++)
        if (s[i] == 'g')
            gidx.push_back(i);
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == c)
        {
            int j = upper_bound(all(gidx), i) - gidx.begin();
            if (j == gidx.size())
                ans = max(ans, n - i + gidx[0]);
            else
                ans = max(ans, gidx[j] - i);
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