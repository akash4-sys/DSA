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

string solve()
{
    int n = II;
    string s = SS, r = SS;
    for (int i = 2; i < n; i += 2)
        if (r[i] == '<' && (s[i - 1] == '<' || s[i + 1] == '<'))
            return "no";
    return "yes";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}