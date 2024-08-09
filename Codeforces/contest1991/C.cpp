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

vec solve()
{
    int n = II, k = 40;
    vec v(n), ans;
    iv(v);

    while (k--)
    {
        ll sum = accumulate(all(v), 0LL);
        if (sum == 0) {
            pl(ans.size());
            return ans;
        }
        
        ll avg = ceil(sum / (n * 1.0));
        for (ll &a : v)
            a = abs(a - avg);
        ans.push_back(avg);
    }

    ll sum = accumulate(all(v), 0LL);
    if (sum == 0) {
        pl(ans.size());
        return ans;
    }
    return {-1};
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}