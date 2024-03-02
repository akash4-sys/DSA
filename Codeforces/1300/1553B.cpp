#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << endl

string solve()
{
    string s = SS, p = SS;
    for (int i = 0; i < s.size(); i++)
    {
        string a = s.substr(0, i + 1), b = s.substr(0, i);
        reverse(all(b));
        a += b;
        if (a.find(p) != string::npos)
            return "YES";
    }
    return "NO";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}