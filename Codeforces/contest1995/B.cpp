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
    ll n = LL, m = LL, ans = 0, sum = 0;
    vec v(n);
    iv(v);
    sort(all(v));
    map<ll, ll> mp;

    for (int i = 0, j = 0; i < n; i++)
    {
        if (i && v[i] - v[i - 1] > 1)
            sum = 0, mp.clear(), j = i;

        sum += v[i];
        mp[v[i]]++;
        while (j <= i && (sum > m || mp.size() > 2)) {
            mp[v[j]]--;
            if (mp[v[j]] == 0)
                mp.erase(v[j]);
            sum -= v[j];
            j++;
        }
        ans = max(ans, sum);
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