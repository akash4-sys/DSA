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

int solve()
{
    int n = II, ans = 0, m = n / 3, cnt[3] = {0};
    vec v(n);
    for (int &a : v)
        a = II % 3, cnt[a]++;
    
    if (cnt[0] == cnt[1] && cnt[1] == cnt[2] && cnt[0] == m)
        return 0;
    
    for (int r = 0; r < 3; r++)
        for (int i = 1; i < 3 && cnt[r] > m; i++)
            if (cnt[(r + i) % 3] < m)
            {
                int k = min(m - cnt[(r + i) % 3], cnt[r] - m);
                cnt[r] -= k;
                cnt[(r + i) % 3] += k;
                ans += (k * i);
            }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}