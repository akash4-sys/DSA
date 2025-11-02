#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II, m = II;
    vec cnt(n + 1, 0), st(n, 0), ans(n), end(n, 0);
    iota(all(ans), 0);
    for (int i = 0; i < m; i++) {
        int l = II - 1, r = II - 1;
        cnt[l]++;
        cnt[r + 1]--;
        st[l] = end[r] = 1;
    }

    // final mex = 0
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
        if (cnt[i] == m) {
            swap(ans[i], ans[0]);
            pv(ans);
            return;
        }
    }

    // final mex = 1
    for (int i = 0; i < n - 1; i++)
        if (!end[i]) {
            swap(ans[i], ans[0]);
            if (i == 1)
                swap(ans[i + 1], ans[0]);
            else
                swap(ans[i + 1], ans[1]);
            pv(ans);
            return;
        }
        else if (!st[i + 1]) {
            swap(ans[i], ans[1]);
            if (i == 0)
                swap(ans[i + 1], ans[1]);
            else
                swap(ans[i + 1], ans[0]);
            pv(ans);
            return;
        }
    
    // final mex = 2
    swap(ans[1], ans[2]);
    pv(ans);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}