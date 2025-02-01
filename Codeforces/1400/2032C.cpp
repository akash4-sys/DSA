#include <bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, ans = n - 1;
    vec v(n);
    iv(v);
    sort(v.begin(), v.end());
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[v[i]] = i;
    
    for (auto &it : mp)
    {
        int res = n - it.second - 1, l = 0, r = it.second - 1, mn = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (v[mid] + v[mid + 1] > it.first)
                r = mid - 1, mn = min(mn, mid);
            else
                l = mid + 1;
        }
        ans = min(ans, res + mn);
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