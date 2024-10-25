#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}

ll solve()
{
    int n = II, ans = 0;
    vec v(n);
    iv(v);
    for (int i = 1; i < n; i++) {
        int x = max(v[i - 1], v[i]), y = min(v[i - 1], v[i]);
        if (ceil_div(x, y) > 2)
            while (x > y * 2)
                x = (x + 1) / 2, ans++;
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}