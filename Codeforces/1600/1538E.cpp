#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define p pair<string, ll>

ll Count(string s) {
    int cnt = 0, i = -1;
    while ((i = s.find("haha", i + 1)) != string::npos)
        cnt++;
    return cnt;
}

p merge(p &a, p &b)
{
    auto [ls, lc] = a;
    auto [rs, rc] = b;
    int l = ls.size(), r = rs.size();
    ll cnt = lc + rc + Count(ls.substr(max(l - 3, 0)) + rs.substr(0, min(r, 3)));
    return {ls.substr(0, min(l, 3)) + rs.substr(max(r - 3, 0)), cnt};
}

ll solve()
{
    int n = II;
    string prev;
    map<string, p> mp;
    for (int i = 0; i < n; i++)
    {
        string var = SS, op = SS, a = SS;
        if (op == ":=")
            mp[var] = {a, Count(a)};
        else {
            string op2 = SS, b = SS;
            mp[var] = merge(mp[a], mp[b]);
        }
        prev = var;
    }
    return mp[prev].second;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}