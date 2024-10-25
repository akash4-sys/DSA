#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

ll solve()
{
    ll x = LL, y = LL, a = LL, b = LL;
    if (a == b)
        return min(x, y) / a;
    
    if (a < b)
        swap(a, b);

    ll l = 0, r = 1e9 + 100;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll right = floorl((x - m * b) * 1.0l / (a - b));
        ll left = ceill((y - m * a) * 1.0l / (b - a));
        if (max(left, 0ll) <= min(right, m))
            l = m;
        else
            r = m;
    }
    return l;
}

int main()
{
    fast;
    for (int tc = LL; tc; tc--)
        cout << solve() << "\n";
    return 0;
}