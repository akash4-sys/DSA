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

unordered_set<char> v = {'a', 'e'}, cn = {'b', 'c', 'd'};

string solve()
{
    int n = II;
    string s = SS, r = "";

    for (int i = n - 1; i >= 0; i--)
        if (v.count(s[i]))
        {
            r += s[i];
            r += s[i - 1];
            r += ".";
            i--;
        }
        else
        {
            r += s[i];
            r += s[i - 1];
            r += s[i - 2];
            r += ".";
            i -= 2;
        }
    
    r.pop_back();
    reverse(all(r));
    return r;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}