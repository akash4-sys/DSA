#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
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

bool f(string &s) {
    for (int i = 0, j = s.size() - 1; i <= j; i++, j--)
        if (s[i] != s[j])
            return 0;
    return 1;
}

void solve()
{
    int n = II;
    string s = SS;
    for (int mask = 0; mask < (1 << n); mask++) {
        string p = "";
        char prev = '`';
        int flag = 1, cnt = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) {
                if (s[i] == '0' && prev == '1') {
                    flag = 0;
                    break;
                }
                cnt++;
                prev = s[i];
            }
            else p += s[i];
        
        if (flag && f(p)) {
            pl(cnt);
            for (int i = 0; i < n; i++)
                if (mask & (1 << i))
                    cout << i + 1 << " ";
            br;
            return;
        }
    }
    pl(-1);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}