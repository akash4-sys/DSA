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
    ll n = II, k = II, i = 1, ans = 0;
    vec v(k);
    iv(v);
    sort(all(v));
    while (i < k && v[i] == 1)
        v.back()++, ans++, i++;
    
    while (v.back() != n && i < k) {
        ll d = n - v.back();
        ans += ((min(d, v[i]) - 1) * 2) + 1;
        v.back() += min(d, v[i]);
        i++;
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}