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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void sub(int &a, int &b)
{
    if (a >= b)
        a -= b, b = 0;
    else
        b -= a, a = 0;
}

string solve()
{
    int n = II, k = II;
    vec h(n), pos(n);
    iv(h);
    iv(pos);

    vv v;
    for (int i = 0; i < n; i++)
        v.push_back({abs(pos[i]), h[i]});
    sort(all(v));

    for (int t = 0, i = 0; t <= n && i < n; t++)
        for (int dmg = k; dmg && i < n;)
        {
            int d = v[i][0] - t;
            if (d <= 0)
                return "NO";
            
            sub(v[i][1], dmg);
            i += (v[i][1] == 0);
        }
    return "YES";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}