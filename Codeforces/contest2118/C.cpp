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
    ll n = LL, k = LL, ans = 0, cnt[64] = {0};
    for (int i = 0; i < n; i++) {
        ll a = II;
        for (int j = 0; j < 64; j++)
            if (a & (1LL << j)) ans++;
            else cnt[j]++;
    }

    for (int i = 0; i < 64; i++) {
        ll m = k / (1LL << i), x = min(m, cnt[i]);
        ans += x;
        k -= (x * (1LL << i));
        cnt[i] -= x;
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