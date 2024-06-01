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

bool solve()
{
    int n = II, j = 0;
    string s = SS, t = SS;
    if (count(s.begin(), s.end(), 'b') != count(t.begin(), t.end(), 'b'))
        return 0;
    
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'b')
            continue;
        while (t[j] == 'b')
            j++;
        if (s[i] != t[j] || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j))
            return 0;
        j++;
    }
    return 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}