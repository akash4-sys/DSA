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

ll solve()
{
    int n = II, flag = 1, cnt = 0;
    vec a(n), b(n);
    iv(a); iv(b);

    while (flag) {
        int nxt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > b[i]) {
                a[i]--;
                nxt = 1;
                break;
            }
        for (int i = 0; i < n; i++)
            if (a[i] < b[i]) {
                a[i]++;
                break;
            }
        flag = nxt;
        cnt++;
    }
    return cnt;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}