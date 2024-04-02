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

bool isBinary(int n)
{
    for (; n; n /= 10)
        if (n % 10 != 0 && n % 10 != 1)
            return 0;
    return 1;
}

int rec(int n)
{
    if (isBinary(n))
        return 1;
    
    for (int i = 2, sq = sqrt(n); i <= sq; i++)
        if (n % i == 0)
        {
            int m = n / i;
            if (m != i && isBinary(m) && rec(n / m))
                return 1;
            if (isBinary(i) && rec(n / i))
                return 1;
        }
    return 0;
}

string solve()
{
    int n = II;
    return rec(n) ? "YES" : "NO";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}