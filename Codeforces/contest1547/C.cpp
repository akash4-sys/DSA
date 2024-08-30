#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
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

vec solve()
{
    int k = II, n = II, m = II, i = 0, j = 0, x = 0;
    vec a(n), b(m), v;
    iv(a);
    iv(b);

    while (i < n || j < m)
    {
        int p = v.size();
        while (i < n && !a[i])
            v.push_back(0), i++, k++;
        while (j < m && !b[j])
            v.push_back(0), j++, k++;
        
        if (i < n && a[i] <= k)
            v.push_back(a[i++]);
        else if (j < m && b[j] <= k)
            v.push_back(b[j++]);
        if (v.size() == p)
            return {-1};
    }
    return v;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}