#ifdef __INTELLISENSE__
#include "../headers.h"
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
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v, n) { for(int i = 0; i < n; i++) cin >> v[i]; }

void solve()
{
    string s = to_string(II);
    int x = 0, y = 0, t = 0;
    for (char &c : s)
    {
        int d = c - '0';
        if (d % 2 == 0)
            x = (x * 10) + (d / 2), y = (y * 10) + (d / 2);
        else
        {
            int a = (d + 1) / 2, b = (d - 1) / 2;
            if (t)
                swap(a, b);
            t ^= 1;
            x = (x * 10) + a, y = (y * 10) + b;
        }
    }
    pf(x)<<" "<<y<<endl;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}