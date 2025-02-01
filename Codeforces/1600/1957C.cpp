#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })

ll solve()
{
    ll n = LL, k = LL, moves = 0, mod = 1e9 + 7;
    for (int i = 0, r, c; i < k; i++) {
        cin >> r >> c;
        moves += 2 - (r == c);
    }
    
    ll rem = n - moves, a = 1, b = 1;
    for (int i = 2; i <= rem; i++) {
        ll c = (b + (2LL * (i - 1) * a) % mod) % mod;
        a = b;
        b = c;
    }
    return b;
}
int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}