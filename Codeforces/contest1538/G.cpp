#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

ll bs(ll x, ll y, ll a, ll b)
{
    ll l = 0, r = min(x / a, y / b), ans = 0;
    while (l <= r) {
        ll n = (l + r) / 2;
        ll rx = x - (n * a), ry = y - (n * b);
        ll m = min(rx / b, ry / a);
        if (n + m >= ans)
            ans = n + m, l = n + 1;
        else
            r = n - 1;
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = LL; tc; tc--) {
        ll x = LL, y = LL, a = LL, b = LL;
        ll res = max(bs(x, y, a, b), bs(x, y, b, a));
        cout << res << "\n";
    }
    return 0;
}