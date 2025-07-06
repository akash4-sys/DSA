#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define iv(v) { for(auto &x : v) cin >> x; }

int op(int a, int b)
{
    int x = a;
    while (x % 2 == 0 && x / 2 != b)
        x /= 2;
    if (x % 2)
        return a / x;
    
    int y = x;
    while (y % 2 == 0)
        y /= 2;
    return (a - x) / y + 1;
}

bool solve()
{
    int n = II, k = II;
    vec v(n), pf(n, 0), sf(n, 0);
    iv(v);
    for (int i = 1; i < n; i++)
        pf[i] += pf[i - 1] + op(v[i - 1],  v[i]);
    for (int i = n - 2; i >= 0; i--)
        sf[i] += sf[i + 1] + op(v[i + 1], v[i]);
    
    for (int i = 0; i < n; i++)
        if (sf[i] + pf[i] + op(v[i], 0) >= k)
            return 1;
    return 0;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}