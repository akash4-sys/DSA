#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << endl

int solve()
{
    int n = II;
    string s = SS;
    vector<string> v = {"aa", "aca", "aba", "acba", "abca", "abbacca", "accabba"};
    for (auto &p : v)
        if (s.find(p) != string::npos)
            return p.size();
    return -1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}