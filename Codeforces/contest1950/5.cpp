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

vec factors(int x)
{
    vec v;
    for (int i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0)
        {
            if (x / i != i)
                v.push_back(x / i);
            v.push_back(i);
        }
    return v;
}

int solve()
{
    int n = II, ans = n;
    string s = SS;
    for (int f : factors(n))
    {
        // front
        string p = "";
        for (int i = 0; i < f; i++)
            p += s[i];
        
        int d = 0;
        for (int i = f; i < n;)
            for (int j = 0; j < f; j++, i++)
                d += (s[i] != p[j]);
        
        if (d <= 1) {
            ans = min(ans, f);
            continue;
        }

        // back
        p = "";
        for (int i = n - f; i < n; i++)
            p += s[i];
        
        d = 0;
        for (int i = 0; i < n;)
            for (int j = 0; j < f; j++, i++)
                d += (s[i] != p[j]);
        
        if (d <= 1)
            ans = min(ans, f);
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