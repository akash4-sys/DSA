#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })

string d = "NEWS", r = "RH";

string solve()
{
    int n = II;
    string s = SS;
    if (n % 2 || n == 2 && s[0] != s[1])
        return "NO";
    if (n == 2 && s[0] == s[1])
        return r;
    
    vector<vector<int>> ch(4);
    for (int i = 0; i < n; i++)
        ch[d.find(s[i])].push_back(i);
    
    s = string(n, '#');
    for (int i = 0, x = 0; i < 2; i++)
        if (ch[i].size() % 2)
        {
            if (ch[3 - i].size() % 2 == 0)
                return "NO";

            int f = min(ch[i].size(), ch[3 - i].size());
            while (f--) {
                s[ch[i].back()] = s[ch[3 - i].back()] = r[x];
                ch[i].pop_back(), ch[3 - i].pop_back();
                x ^= 1;
            }
        }
    
    for (int i = 0; i < 4; i++) {
        if (ch[i].size() % 2)
            return "NO";
        for (int j = 0, x = 0; j < ch[i].size(); j++, x ^= 1)
            s[ch[i][j]] = r[x];
    }
    return s;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}