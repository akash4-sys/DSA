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

long long power(long long a, long long b, long long mod)
{
    long long res = 1;
    for (a %= mod; b > 0; b >>= 1)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

ll solve(ll n, ll k)
{
    if (!k || n == k)
        return 1;
    return power(2, k, 1e9 + 7);
}

int main()
{
    fast;
    int t = II;
    vector<ll> vn(t), vc(t);
    iv(vn);
    iv(vc);
    for (int i = 0; i < t; i++)
        pl(solve(vn[i], vc[i]));
    return 0;
}