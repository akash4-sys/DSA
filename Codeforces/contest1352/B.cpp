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
    int n = II, k = II, sum = (k - 1) * 2;
    if (n > sum && (n - sum) % 2 == 0) {
        cout << "YES\n";
        for (int i = 1; i < k; i++)
            cout << "2 ";
        cout << n - sum << "\n";
        return;
    }

    if (n > k - 1 && (n - k + 1) % 2) {
        cout << "YES\n";
        for (int i = 1; i < k; i++)
            cout << "1 ";
        cout << n - k + 1 << "\n";
        return;
    }

    cout << "NO\n";
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}