#include <bits/stdc++.h>

using namespace std;

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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II, q = II;
    string s = " " + SS, r = " " + SS;
    vv sum(n + 1, vec(26, 0));

    for (int i = 1; i <= n; i++) {
        sum[i][s[i] - 'a']--;
        sum[i][r[i] - 'a']++;
        for (int j = 0; j < 26; j++)
            sum[i][j] += sum[i - 1][j];
    }

    while (q--)
    {
        int l = II, r = II, ans = 0;
        for (int i = 0; i < 26; i++)
            ans += max(sum[r][i] - sum[l - 1][i], 0);
        cout << ans << "\n";
    }
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}