#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ Long a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(vv) { for(auto &v : vv) pv(v), br; }

bool solve(int n, int a, int b, int r)
{
    for (int i = 0; (i * a) < n; i++)
        if ((n - (i * a)) % b == 0)
        {
            pl("YES");
            vec v;
            if (r)
                v = {(n - (i * a)) / b, i};
            else
                v = {i, (n - (i * a)) / b};
            pv(v);
            return 1;
        }
    return 0;
}

int main()
{
    fast;
    int n = II, a = II, b = II;
    if(!solve(n, a, b, 0) && !solve(n, b, a, 1))
        pl("NO");
    return 0;
}