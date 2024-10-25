#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define CC ({ char a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }

bool solve()
{
    int n = II;
    vector<vector<int>> a(n), b(n);
    for (auto &v : a)
        for (int i = 0; i < n; i++)
            v.push_back(CC - '0');
    for (auto &v : b)
        for (int i = 0; i < n; i++)
            v.push_back(CC - '0');
    
    auto check = [&](){
        for (int j = 0; j < n; j++)
            if (a[0][j] != b[0][j])
                for (int i = 0; i < n; i++)
                    a[i][j] ^= 1;
        
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                if ((a[i][j - 1] ^ b[i][j - 1]) != (a[i][j] ^ b[i][j]))
                    return 0;
        return 1;
    };
    
    for (int t = 2; t--;) {
        if (check())
            return 1;
        for (int i = 0; i < n; i++)
            a[0][i] ^= 1;
    }
    return 0;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}