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

int solve()
{
    int n = II, k = II, cnt = 0, prev = 0, c = 0, ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[II]++;
    
    vector<vector<int>> v;
    for (auto &it : mp)
        v.push_back({it.first, it.second});
    
    for (int i = 0, j = 0; i < v.size(); i++) {
        if (prev + 1 != v[i][0])
            c = 0, prev = 0, cnt = 0, j = i;
        if (c == k)
            cnt -= v[j++][1], c--;

        c++;
        prev = v[i][0];
        cnt += v[i][1];
        ans = max(ans, cnt);
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