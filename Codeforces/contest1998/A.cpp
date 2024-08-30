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

void solve()
{
    ll a = II, b = II, k = II, ak = a * k, bk = b * k, sum = 0;
    if (k == 1) {
        pf(ak) << " " << bk << "\n";
        return;
    }

    for (int i = 2; i < k; i++) {
        pf(i) << " " << i << "\n";
        sum += i;
    }

    for (int i = k; ; i++)
        if ((ak - sum - i >= k && ak - sum - i != i) || ak - sum - i < 2) {
            pf(i) << " " << i << "\n";
            pf(ak - sum - i) << " " << (bk - sum - i) << "\n";
            break;
        }
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}