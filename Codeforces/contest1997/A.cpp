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
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

string solve()
{
    string s = SS;
    int flag = 0;
    for (int i = 1; i < s.size() && !flag; i++)
        if (s[i] == s[i - 1])
        {
            for (char c = 'a'; c <= 'z'; c++)
                if (s[i] != c) {
                    s = s.substr(0, i) + c + s.substr(i);
                    flag = 1;
                    break;
                }
        }
    
    if (!flag) {
        for (char c = 'a'; c <= 'z'; c++)
            if (s.back() != c) {
                s += c;
                break;
            }
    }
    return s;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}