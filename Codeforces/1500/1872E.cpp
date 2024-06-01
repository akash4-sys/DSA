#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II;
    vector<ll> a(n), pf(n + 1, 0), v(2, 0);
    iv(a);
    string s = SS;

    for (int i = 0; i < n; i++)
        pf[i + 1] = pf[i] ^ a[i], v[s[i] - '0'] ^= a[i];
    
    for (int q = II; q--;)
    {
        int type = II;
        if (type == 1) {
            int l = II, r = II;
            v[0] ^= (pf[r] ^ pf[l - 1]);
            v[1] ^= (pf[r] ^ pf[l - 1]);
        }
        else {
            int g = II;
            cout << v[g] << " ";
        }
    }
    cout << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}