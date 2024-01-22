#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
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

vector<ll> prime;

void msieve(ll n)
{
    vector<ll> isprime(n, 1), SPF(n);
    isprime[0] = isprime[1] = 0;
    for (ll int i = 2; i < n; i++)
    {
        if (isprime[i])
            prime.push_back(i), SPF[i] = i;
        for (ll int j = 0; j < (int)prime.size() && i * prime[j] < n && prime[j] <= SPF[i]; j++)
        {
            isprime[i * prime[j]] = false;
            SPF[i * prime[j]] = prime[j];
        }
    }
}

ll solve()
{
    ll diff = LL;
    ll b = prime[lower_bound(all(prime), diff + 1) - prime.begin()];
    ll c = prime[lower_bound(all(prime), diff + b) - prime.begin()];
    return b * c;
}

int main()
{
    fast;
    msieve(1e5);
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}