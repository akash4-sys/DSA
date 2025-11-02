#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
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

ll solve()
{
    ll a = LL, b = LL, ans = 0;
    if ((a % 2) && (b % 2)) {
        ans = max(ans, a + b);
        ans = max(ans, a * b + 1);
        return ans;
    }

    if (a % 2) {
        if (b % 4) return -1;
        ans = max(ans, a * 2 + (b / 2));
        ans = max(ans, a * (b / 2) + 2);
        return ans;
    }
    
    if (b % 2) return -1;
    return max(a + b, a * (b / 2) + 2);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}