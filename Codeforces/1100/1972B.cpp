#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

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

vector<string> v = {"UUU", "UUD", "DUU", "DUD"};

bool solve()
{
    int n = II, a = 1;
    string s = SS;
    while (!s.empty())
    {
        int k = s.size();

        if (s.size() < 3) {
            int i = s.find('U');
            if (i != string::npos) {
                s.erase(i, 1);
                
            }
            return 
        }

        for (auto &p : v)
        {
            auto i = s.find(p);
            if (i != string::npos) {
                s.erase(i, 1);
                break;
            }

            if (s.back() == p[0] && s[0] == p[1] && s[1] == p[2]) {
                s.erase(s.begin());
                break;
            }

            if (end(s)[-2] == p[0] && end(s)[-1] == p[1] && s[0] == p[2]) {
                s.pop_back();
                break;
            }
        }

        if (k == s.size())
            return !a;
        a ^= 1;
    }
    return a;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}