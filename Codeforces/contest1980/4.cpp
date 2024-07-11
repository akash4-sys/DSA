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

bool del(vec a, int k)
{
    a.erase(a.begin() + k);
    vec b;
    for (int i = 1; i < a.size(); i++)
        b.push_back(__gcd(a[i - 1], a[i]));
    return is_sorted(all(b));
}

bool solve()
{
    int n = II;
    vec a(n), b;
    iv(a);

    for (int i = 1; i < n; i++)
    {
        int g = __gcd(a[i], a[i - 1]);
        if (b.size() && b.back() > g)
        {
            bool res = del(a, i) || del(a, i - 1);
            if (i - 2 >= 0)
                res |= del(a, i - 2);
            if (i + 1 < n)
                res |= del(a, i + 1);
            return res;
        }
        b.push_back(g);
    }
    return is_sorted(all(b));
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}