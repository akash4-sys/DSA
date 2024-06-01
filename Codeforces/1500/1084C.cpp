#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SS ({ string s; cin>>s; s; })

int main()
{
    fast;
    ll ans = 1, mod = 1e9 + 7;
    string s = SS, r = "";
    vector<ll> v;
    for (char &c : s)
        if (c == 'b')
            r = c;
        else if (c == 'a') {
            if (r[0] == 'a')
                v.back()++;
            else
                v.push_back(1);
            r = c;
        }
    
    if (v.empty()) {
        cout << 0;
        return 0;
    }
    
    for (ll &a : v)
        (ans *= (a + 1)) %= mod;
    cout << ans - 1;
    return 0;
}