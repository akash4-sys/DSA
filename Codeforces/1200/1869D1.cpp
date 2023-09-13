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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

string solve()
{
    int n = II;
    vec v(n);
    iv(v); 
    ll sum = accumulate(all(v), 0LL);
    if (sum % n)
        return "NO";
    
    sum /= n;
    vector<int> bit(31, 0);
    for (int i = 0; i < n; i++)
        if (v[i] != sum)
        {
            int d = abs(v[i] - sum);
            int p = d & -d;
            int e = d + p;
            if (__builtin_popcount(e) != 1)
                return "NO";
            if (v[i] > sum)
                bit[__lg(e)]++, bit[__lg(p)]--;
            else
                bit[__lg(e)]--, bit[__lg(p)]++;
        }
    
    for (int i = 0; i < 31; i++)
        if (bit[i])
            return "NO";
    return "YES";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}