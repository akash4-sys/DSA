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

bool isPrime(ll n)
{
    if (n == 1)
        return 0;
    for (ll i = 2, sq = sqrt(n); i <= sq; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

string solve()
{
    string s = SS;
    for (int i = 0; i < 512; i++)
    {
        string r = "";
        for (int j = 0; j < 9; j++)
            if (i & (1 << j))
                r += s[j];
        
        if (r.size() >= 2 && isPrime(stoll(r)))
            return r;
    }
    return "-1";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}