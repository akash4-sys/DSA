#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int main()
{
    fast;
    int n = (2 * II) + 1, k = II;
    vec v(n);
    iv(v);
    for (int i = 1; i < n - 1 && k; i++)
        if (i % 2 && v[i - 1] < v[i] - 1 && v[i] - 1 > v[i + 1])
            v[i]--, k--;
    pv(v);
    return 0;
}