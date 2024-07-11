#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SS ({ string s; cin>>s; s; })

int main()
{
    fast;
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s = SS;
        int n = s.size(), m = 0;
        vector<bool> prev(26, 0);
        for (char &c : s)
            if (prev[c - 'a']) {
                m += 2;
                fill(prev.begin(), prev.end(), 0);
            }
            else
                prev[c - 'a'] = 1;
        cout << n - m << "\n";
    }
    return 0;
}