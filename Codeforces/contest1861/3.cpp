#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })

// worng solution

bool solve()
{
    string s = SS;
    int inc = 0, dec = 0, plus = 0, minus = 0, one = 0;
    for (char &c : s)
        if (c == '0')
        {
            if (inc + dec < 2)
                return 0;
            if (one && plus <= minus)
                return 0;
            if (dec == 0)
                inc--, dec++;
        }
        else if (c == '1')
        {
            if (dec != 0)
                return 0;
            one = 1;
            plus = minus = 0;
        }
        else if (c == '+')
        {
            dec ? dec++ : inc++;
            plus++;
        }
        else
        {
            dec ? dec-- : inc--;
            minus++;
        }
    return 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}