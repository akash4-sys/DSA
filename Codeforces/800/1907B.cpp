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
    string s = SS;
    unordered_map<int, int> mp;
    stack<int> l, u;
    for (int i = 0; i < s.size(); i++)
    {
        if (isupper(s[i]) && s[i] == 'B' && u.size())
            mp[u.top()]++, mp[i]++,  u.pop();
        else if (islower(s[i]) && s[i] == 'b' && l.size())
            mp[l.top()]++, mp[i]++, l.pop();
        else
        {
            if (isupper(s[i]))
                u.push(i);
            if (islower(s[i]))
                l.push(i);
        }
    }

    string ans = "";
    for (int i = 0; i < s.size(); i++)
        if (!mp.count(i) && s[i] != 'B' && s[i] != 'b')
            ans += s[i];
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}