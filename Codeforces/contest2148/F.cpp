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

vec solve()
{
    int n = II, maxk = 0;
    vv v(n);
    for (int i = 0; i < n; i++) {
        int k = II;
        maxk = max(maxk, k);
        while (k--) {
            int a = II;
            v[i].push_back(a);
        }
    }
    
    int j = 0;
    vec ans, vis(n, 0);
    auto f = [&]() -> int {
        while (row.size() > 1)
        {
            set<int> crow;
            int x = INT_MAX;
            for (int i : row)
                if (j < v[i].size())
                    x = min(x, v[i][j]);
                
            if (x == INT_MAX)
                return 0;

            for (auto it = row.begin(); it != row.end(); it = row.begin()) {
                int i = *row.begin();
                if (j < v[i].size() && v[i][j] == x)
                    crow.insert(i);
                row.erase(it);
            }

            row = crow;
            ans.push_back(x);
            j++;
        }
        return *(row.begin());
    };

    while (j < maxk) {
        int i = f(row);
        while (ans.size() < v[i].size())
            ans.push_back(v[i][ans.size()]);
        j = v[i].size();
        vis[i] = 1;
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}