#include <bits/stdc++.h>
using namespace std;

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
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    ll n = LL, alice = 0, bob = 0, l = 0, r = n - 1, turn = 0;
    vec a(n), ans(3, 0);
    iv(a);

    for (;l <= r; turn ^= 1)
    {
        if (!turn) {
            alice = 0;
            while (l <= r && alice <= bob)
                alice += a[l++];
            ans[1] += alice;
        }
        else {
            bob = 0;
            while (l <= r && bob <= alice)
                bob += a[r--];
            ans[2] += bob;
        }
        ans[0]++;
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}