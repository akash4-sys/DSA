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

string solve()
{
    int n = II, m = II, digits = 0;
    vec zero(n);
    for (int i = 0; i < n; i++) 
    {
        int a = II;
        for (; a % 10 == 0; a /= 10, zero[i]++);
        for (; a; a /= 10, digits++);
    }

    sort(all(zero), greater<int>());
    for (int i = 1; i < n; i += 2)
        digits += zero[i];
    return digits > m ? "Sasha" : "Anna"; 
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}