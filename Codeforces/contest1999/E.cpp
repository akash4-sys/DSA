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

// 12
vec v = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441};

int op(ll n)
{
    ll res = 0;
    while(n)
        res++, n /= 3;
    return res;
}

ll solve()
{
    ll l = LL, r = LL, ans = op(l), i = 0;
    for (; i < v.size(); i++)
        if (v[i] >= l)
        {
            if (v[i] > r)
                break;
            ans += ((v[i] - l) * i);
            l = v[i];
        }
    
    ans += (r - l + 1) * (i);
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