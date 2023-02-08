#ifdef __INTELLISENSE__
#include "../headers.h"
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
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(vv) { for(auto &v : vv) pv(v), br; }

int solve(string &s)
{
    if (s.size() % 2)
        return -1;
    int i = 0, j = 0;
    for (char &c : s)
    {
        i += (c == 'U');
        i -= (c == 'D');
        j += (c == 'R');
        j -= (c == 'L');
    }
    return ((abs(i) + abs(j)) / 2);
}

int main()
{
    fast;
    string s = SS;
    pf(solve(s));
    return 0;
}