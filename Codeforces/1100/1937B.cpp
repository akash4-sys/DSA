#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        int n = II, max_down = n, min_down = 1;
        string a = SS, b = "1" + SS;
        for (int i = n - 1; i >= 1; i--)
            if (a[i] == '1' && b[i] == '0')
                max_down = i;

        for (int i = 0; i < max_down; i++)
            if (b[i] == '1' && a[i] == '0')
                min_down = i + 1;
        
        cout << a.substr(0, max_down) + b.substr(max_down) << endl;
        cout << max_down - min_down + 1 << endl;
    }
    return 0;
}