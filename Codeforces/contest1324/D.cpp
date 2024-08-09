#include <bits/stdc++.h>

using namespace std;

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

ll solve()
{
    ll n = II, ans = 0;
    vec a(n);
    iv(a);
    for (int i = 0; i < n; i++)
        a[i] -= II;

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        if (a[i] > 0) {
            int j = lower_bound(a.begin(), a.end(), -a[i] + 1) - a.begin();
            ans += (i - j);
        }
    return ans;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}