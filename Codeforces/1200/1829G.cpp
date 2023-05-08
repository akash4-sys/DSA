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
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

ll ans[2000007], pf[1500][1500] = {0};

void gen()
{
    ll n = 1;
    for (int i = 1; i < 1500; i++)
        for (int j = i - 1; j >= 1; j--)
        {
            pf[j][i - j] = pf[j - 1][i - j] + pf[j][i - j - 1] - pf[j - 1][i - j - 1] + (n * n);
            ans[n++] = pf[j][i - j];
        }
}

ll solve()
{
    int n = II;
    return ans[n];   
}

int main()
{
    fast;
    gen();
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}