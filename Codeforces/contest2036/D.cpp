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

string r = "1543";

int search(string &s)
{
    if (s.size() < 4)
        return 0;
    
    for (int i = 0; i < 3; i++)
        s += s[i];
    int count = 0, pos = s.find(r);
    while (pos != string::npos) {
        count++;
        pos = s.find(r, pos + r.size());
    }
    return count;
}

int solve()
{
    int n = II, m = II, cnt = 0, ans = 0;
    vector<string> grid(n);
    for (auto &v : grid)
        cin >> v;
    
    swap(n, m);
    for (int i = 0; cnt < m * n; ++i)
    {
        string s = "";
        for (int j = i; j < n - i; ++j)
            s += grid[i][j], cnt++;
        for (int j = i + 1; j < m - i; ++j)
            s += grid[j][n - i - 1], cnt++;
        for (int j = n - i - 2; m - i - 1 != i && j >= i; --j)
            s += grid[m - i - 1][j], cnt++;
        for (int j = m - i - 2; n - i - 1 != i && j > i; --j)
            s += grid[j][i], cnt++;
        ans += search(s);
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