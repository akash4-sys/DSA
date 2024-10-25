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
    ll n = II, ans = 0, prev_op = 0;
    vec v(n);
    iv(v);

    for (int i = 1; i < n; i++)
    {
        ll cnt = 0, prev = v[i - 1], curr = v[i];
        if (prev > 1 && curr == 1)
            return -1;
        
        while (prev != 1 && prev * prev <= curr)
            prev *= prev, cnt--;
        while (curr < prev)
            curr *= curr, cnt++;
        
        ll op = max(prev_op + cnt, 0LL);
        ans += op;
        prev_op = op;
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