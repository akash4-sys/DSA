#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<char>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

char solve()
{
    vv v(3, vec(3, 'a'));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> v[i][j];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (v[i][j] == '?')
            {
                int ch[26] = {0};
                for (int k = 0; k < 3; k++)
                    ch[v[i][k] - 'A']++;
                for (int k = 0; k < 3; k++)
                    ch[v[k][j] - 'A']++;
                for (int k = 0; k <= 3; k++)
                    if (!ch[k])
                        return char(k + 'A');
            }
    return 'A';
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}