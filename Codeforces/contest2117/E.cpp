
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
    int n = II, ans = 0;
    vec a(n), b(n);
    map<int, vector<int>> mpa, mpb;
    for (int i = 0; i < n; i++)
        a[i] = II, mpa[a[i]].push_back(i);
    for (int i = 0; i < n; i++)
        b[i] = II, mpb[b[i]].push_back(i);
    
    for (int i = n - 1; i >= 0; i--)
        if (a[i] == b[i]) {
            ans = max(ans, i);
            break;
        }
        else {
            mpa[a[i]].pop_back();
            mpb[b[i]].pop_back();
            if (mpa[a[i]].size())
                ans = max(ans, mpa[a[i]].back());
            if (mpb[b[i]].size())
                ans = max(ans, mpb[b[i]].back());
            if (mpb[a[i]].size() && i - mpb[a[i]].back() != 1)
                ans = max(ans, mpb[a[i]].back());
            if (mpa[b[i]].size() && i - mpa[b[i]].back() != 1)
                ans = max(ans, mpa[b[i]].back());
        }
    return ans + 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}