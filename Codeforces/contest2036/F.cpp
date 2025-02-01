#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

ll XOR(ll r, ll i, ll k)
{
    ll ans = 0, f = r >> i, res = 0;
    f -= ((f << i) + k > r);
    for (int j = 0; j <= (f % 4); j++)
        res ^= (((f - j) << i) + k);
    return res;
}

ll XOR(ll l, ll r, ll p, ll k) {
    return XOR(r, p, k) ^ XOR(l - 1, p, k);
}

ll solve() {
    ll l = LL, r = LL, p = LL, k = LL;
    return XOR(l, r, p, k) ^ XOR(l, r, 0, 0);
}

int main()
{
    fast;
    for (int tc = LL; tc; tc--)
        cout << solve() << "\n";
    return 0;
}