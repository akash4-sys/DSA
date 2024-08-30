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
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, ans = 0;
    vec v(n), cnt(n + 1, 0);
    iv(v);

    for (int k = 0; k < n; k++)
    {
        if (cnt[v[k]]) {
            ans += cnt[v[k]];
            continue;
        }

        int f = 0;
        for (int i = 0, j = 0, sum = v[k]; i < n; i++)
        {
            sum -= v[i];
            while (sum < 0)
                sum += v[j++];
            if (sum == 0 && i - j + 1 >= 2) {
                ans++;
                break;
            }
        }
        if (f)
            cnt[v[k]]++;
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