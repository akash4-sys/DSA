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

vec solve()
{
    ll n = LL, k = LL, x = 0;
    vec v(n + 1, 0);
    for (int i = 1, j = n; i <= n; i++, j--) {
        v[i] = i;
        x += abs(i - j);
    }

    if (k > x || k % 2) {
        pl("NO");
        return {};
    }

    pl("YES");
    if (k == 0)
        return v;

    for (int i = 1, j = n; i < j; i++, j--)
    {
        int d = (j - i) * 2;
        if (d < k)
            swap(v[i], v[j]), k -= d;
        else if (d == k) {
            swap(v[i], v[j]);
            break;
        }
        else if (d > k) {
            swap(v[i], v[i + (k / 2)]);
            break;
        }
    }
    return v;
}

int main()
{
    fast;
    int tc = II;
    while (tc--) {
        auto v = solve();
        if (v.empty())
            continue;
        for (int i = 1; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
    }
    return 0;
}