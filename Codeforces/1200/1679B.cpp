#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

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

// void solve2()
// {
//     ll n = LL, q = LL, sum = 0, a = 0;
//     vec v(n);
//     for (int i = 0; i < n; i++)
//         v[i] = LL, sum += v[i];
//
//     set<ll> st;
//     while (q--)
//     {
//         int type = II;
//         if (type == 1)
//         {
//             ll i = LL - 1, x = LL;
//             ll val = (st.find(i) != st.end() || !a) ? v[i] : a;
//             sum = sum - val + x;
//             v[i] = x;
//             st.insert(i);
//         }
//         else
//         {
//             ll x = LL;
//             sum = n * x;
//             a = x;
//             st.clear();
//         }
//         pl(sum);
//     }
// }


void solve()
{
    ll n = LL, q = LL, sum = 0, a = 0, ai = -1;
    vec v(n), lastQ(n, -1);
    for (int i = 0; i < n; i++)
        v[i] = LL, sum += v[i];
    
    for (int k = 0; k < q; k++)
    {
        int type = II;
        if (type == 1)
        {
            ll i = LL - 1, x = LL;
            ll val =  (ai > lastQ[i]) ? a : v[i];
            sum = sum - val + x;
            v[i] = x;
            lastQ[i] = k;
        }
        else
        {
            ll x = LL;
            sum = n * x;
            a = x;
            ai = k;
        }
        pl(sum);
    }
}

int main()
{
    fast;
    solve();
    return 0;
}