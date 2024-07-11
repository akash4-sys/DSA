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

bool solve()
{
    ll n = LL, c = 0;
    string s = to_string(n), p, q;
    if (s[0] != '1')
        return 0;
    
    for (int i = s.size() - 1; i > 0; i--)
    {
        int d = s[i] - '0', j = 5;
        for (; j <= 9; j++)
            if ((j * 2) % 10 >= d)
                break;
        
        int a = (j * 2) % 10 > d ? j - 1 : j, b = j;
        if (a > b)
            a -= c;
        else
            b -= c;
        
        if (a + b > 9)
            c = 1;
        if (d == 9)
            a = b = 9;
        if (a < 5 || b < 5)
            return 0;
        p += (a + '0');
        q += (b + '0');
    }

    reverse(all(p));
    reverse(all(q));
    if (stoll(p) + stoll(q) != n)
        return 0;
    return 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}