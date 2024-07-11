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

string solve()
{
    ll a = LL, s = LL;
    string b = "";

    while (s)
    {
        int x = s % 10, y = a % 10;
        if (y <= x)
            b += to_string(x - y);
        else
        {
            s /= 10;
            x += 10 * (s % 10);
            if (x >= 10 && x <= 19 && x > y)
                b += to_string(x - y);
            else
                return "-1";
        }
        s /= 10, a /= 10;
    }

    if (a)
        return "-1";
    
    while (b.back() == '0')
        b.pop_back();
    reverse(all(b));
    return b;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}