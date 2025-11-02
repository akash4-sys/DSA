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
    int n = II;
    vec b(n), a(n);
    iv(b);
    
    vv v(n + 1);
    for (int i = 0; i < n; i++)
        v[b[i]].push_back(i);
    
    for (int i = 1; i <= n; i++)
        if (v[i].size() % i != 0)
            return {-1};
    
    int c = 0;
    for (int x = 1; x <= n; x++)
        for (int i = 0; i < v[x].size(); i++) {
            if (i % x == 0) c++;
            a[v[x][i]] = c;
        }
    
    for (int &x : a)
        if (x > n)
            return {-1};
    return a;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}