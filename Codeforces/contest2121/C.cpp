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
    int n = II, m = II, x = 0;
    vv v(n, vec(m, 0));
    vv row(n, vec(101, 0)), col(m, vec(101, 0));
    vec fq(101, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j  < m; j++) {
            v[i][j] = II;
            row[i][v[i][j]]++;
            col[j][v[i][j]]++;
            fq[v[i][j]]++;
            x =  max(x,v[i][j]);
        }
    
    int ri = -1, ci =-1;
    for (int i = 0; i < n; i++) {
        if (!row[i][x])
            continue;
        for (int j = 0; j  < m; j++)
            if (fq[x] - row[i][x] - col[j][x] + (v[i][j] == x) == 0) {
                ri = i, ci = j;
                break;
            }
        if (ri != -1)
            break;
    }
    
    if  (ri == -1 || ci ==-1)
            return x;
    for (int i =  0; i < m; i++)
        v[ri][i]--;
    for (int i =  0; i < n; i++)
        v[i][ci]--;
    v[ri][ci]++;

    int  ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j  < m; j++) {
            ans =  max(ans,v[i][j]);
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