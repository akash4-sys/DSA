#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<string>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int getIdx(char c) {
    return c == 'C' ? 0 : (c == 'D' ? 1 : (c == 'H' ? 2 : 3));
}

void solve()
{
    int n = II;
    char trumpsuit;
    cin >> trumpsuit;
    vv ans, suits(4);
    for (int i = 0; i < n * 2; i++) {
        string card = SS;
        suits[getIdx(card[1])].push_back(card);
    }

    int k = 0, t = getIdx(trumpsuit), sz = suits[t].size();
    sort(all(suits[t]));

    for (int i = 0; i < 4; i++)
        if (int m = suits[i].size(); i != t && m > 0)
        {
            sort(all(suits[i]));
            for (int j = 0; j < m - 1; j += 2)
                ans.push_back({suits[i][j], suits[i][j + 1]});
            
            if (m % 2)
            {
                if (k == sz) {
                    pl("IMPOSSIBLE");
                    return;
                }
                ans.push_back({suits[i].back(), suits[t][k++]});
            }
        }
    
    for (; k < sz - 1; k += 2)
        ans.push_back({suits[t][k], suits[t][k + 1]});   
    pvv(ans);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}