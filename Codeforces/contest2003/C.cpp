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

string solve()
{
    int n = II, ch[26] = {0};
    string s = SS, r = "";
    for (char &c : s)
        ch[c - 'a']++;
    
    vv f(26);
    for (int i = 0; i < 26; i++)
        f[i] = {ch[i], i};

    sort(all(f), greater<vec>());
    while (n)
    {
        for (int i = 0; i < 26 && f[i][0]; i++)
            r += char('a' + f[i][1]), f[i][0]--, n--;
    }
    return r;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}