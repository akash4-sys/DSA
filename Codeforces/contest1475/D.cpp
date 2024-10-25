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
    ll n = LL, m = LL;
    vec v(n), a, q, b;
    iv(v);
    for (int i = 0; i < n; i++) {
        if (II == 1)
            a.push_back(v[i]), b.push_back(1);
        else
            q.push_back(v[i]);
    }

    sort(all(a));
    sort(all(q), greater<ll>());
    for (ll &x : q)
        a.push_back(x), b.push_back(2);
    
    ll sum = 0, cost = 0, ans = INT_MAX;
    for (int i = 0, j = 0; i < n; i++)
    {
        sum += a[i];
        cost += b[i];
        if (sum >= m)
            ans = min(ans, cost);
        while (sum > m) {
            ans = min(ans, cost);
            sum -= a[j];
            cost -= b[j];
            j++;
        }
    }
    return ans == INT_MAX ? -1 : max(ans, 0LL);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}