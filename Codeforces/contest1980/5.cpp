#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vv vector<vector<int>>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vv transpose(vv &v)
{
    vv t(v[0].size(), vector<int>(v.size(), 0));
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v[0].size(); j++)
            t[j][i] = v[i][j];
    return t;
}

bool check(vv a, vv b)
{
    int n = a.size(), m = a[0].size();
    map<int, int> mpa;
    vv jA, jB;
    for (int j = 0; j < m; j++)
        jA.push_back({a[0][j], j}), mpa[a[0][j]]++;
    sort(jA.begin(), jA.end());

    for (int i = 0; i < n; i++)
    {
        int f = 1;
        for (int j = 0; j < m; j++)
            if (!mpa.count(b[i][j])) {
                f = 0;
                break;
            }
        
        if (f) {
            for (int j = 0; j < m; j++)
                swap(b[0][j], b[i][j]), jB.push_back({b[0][j], j});
            break;
        }
    }

    if (jB.empty())
        return 0;
    
    sort(jB.begin(), jB.end());
    for (int j = 0; j < m; j++)
    {
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[a[i][jA[j][1]]]++, mp[b[i][jB[j][1]]]--;
        for (auto &it : mp)
            if (it.second)
                return 0;
    }
    return 1;
}

bool solve()
{
    int n = II, m = II;
    vv a(n, vector<int>(m)), b = a;
    for (auto &r : a)
        iv(r);
    for (auto &r : b)
        iv(r);
    
    if (!check(a, b))
        return 0;
    return check(transpose(a), transpose(b));
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}