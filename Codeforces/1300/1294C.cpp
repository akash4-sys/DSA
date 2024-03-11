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

void primeFactors(vec &v, int n)
{
    if (n == 2)
        v.push_back(n);
    for (int i = 2, sq = sqrt(n); i <= sq; i++)
        for (; !(n % i); n /= i)
            v.push_back(i);
    if (n > 2)
        v.push_back(n);
}

void solve()
{
    int n = II;
    vec v;
    primeFactors(v, n);
    if (v.empty()) {
        pl("NO");
        return;
    }

    int a = v[0], b = 1;
    for (int i = 1; i < v.size() && (b == 1 || b == a); i++)
        b *= v[i];
    int c = n / (a * b);

    if (a != b && a != c && b != c && min({a, b, c}) >= 2) {
        pl("YES");
        pf(a) << b << " " << c << "\n";
        return;
    }
    pl("NO");
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}