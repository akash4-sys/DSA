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
#define iv(v) { for(auto &x : v) x = II - 1; }

vector<ll> solve()
{
    ll n = II, root = -1, d = 2;
    vector<ll> par(n, 0), a(n, 0), dist(n, 0), wt(n, 0);
    iv(par);
    iv(a);
    for (ll i = 0; i < n && root == -1; i++)
        if (par[i] == i)
            root = i;
    
    if (a[0] != root)
        return {-1};

    for (int i = 1; i < n; i++)
    {
        int u = a[i];
        if (!dist[par[u]] && root != par[u])
            return {-1};

        int curr = max(dist[par[u]], dist[a[i - 1]]) + 1;
        wt[u] = curr - dist[par[u]];
        dist[u] = curr;
    }
    return wt;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}