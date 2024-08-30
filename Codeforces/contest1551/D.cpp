#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) {cout << x << "\n"; return;}

void solve()
{
    int n = II, m = II, kh = II, kv = n * m / 2 - kh;
    if (n & 1) {
        kh -= m / 2;
        if (kh < 0)
            pl("NO");
    }
    else if (m & 1) {
        kv -= n / 2;
        if (kv < 0)
            pl("NO");
    }
    if ((kh & 1) || (kv & 1))
        pl("NO");
    pl("YES");
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}