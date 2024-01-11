#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
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

string solve()
{
    string s = SS, t = SS;
    vv idx(26);
    for (int i = 0; i < s.size(); i++)
        idx[s[i] - 'A'].push_back(i);
    
    vec ch(26, 0);
    for (char &c : t)
        ch[c - 'A']++;
    
    int i = -1;
    for (char &c : t)
    {
        int k = idx[c - 'A'].size() - ch[c - 'A'];
        if (k < 0)
            return "NO";
        int j = idx[c - 'A'][k];
        if (j <= i)
            return "NO";
        i = j;
        ch[c - 'A']--;
    }
    return "YES";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}