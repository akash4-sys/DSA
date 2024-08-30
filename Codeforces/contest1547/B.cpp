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

bool solve()
{
    string s = SS;
    int i = s.find('a');
    if (i == string::npos)
        return 0;
    
    int l = i - 1, r = i + 1, ch[26] = {0};
    ch[0] = 1;
    for (int k = 1; k < s.size(); k++)
    {
        if (l >= 0 && s[l] - 'a' == k)
            ch[s[l] - 'a']++, l--;
        else if (r < s.size() && s[r] - 'a' == k)
            ch[s[r] - 'a']++, r++;
        else
            return 0;
    }
    return 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}