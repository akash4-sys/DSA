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
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    ll n = LL, k = LL;
    vv r(k, vec(2, 0));
    for (auto &p : r)
        p[1] = LL;
    for (auto &p : r)
        p[0] = LL + p[1];
    
    sort(r.begin(), r.end(), greater<vec>());
    vec ans(n, 0);
    set<ll> l;

    for (int i = 1; i <= n; i++)
    {
        int j = i - 1;
        while (r.size() && i >= r.back()[1]) {
            l.insert(r.back()[0] - (i * 2));
            r.pop_back();
        }
        ans[j] = r.size() ? r.back()[0] - i : LLONG_MAX;
        ans[j] = l.size() ? min(*l.begin() + i, ans[j]) : ans[j];
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}