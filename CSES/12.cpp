#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    string s, ans = "";
    cin >> s;
    int ch[26] = {0}, odd = 0;
    for (char &c : s)
        ch[c - 'A']++;
    
    char c = '1';
    for (int i = 0; i < 26; i++)
    {
        if (ch[i] % 2 != 0)
            odd++, c = i + 'A', ch[i]--;
        if (odd > 1) {
            cout << "NO SOLUTION";
            return 0;
        }
        ans += string(ch[i] / 2, char(i + 'A'));
    }

    string r = ans;
    reverse(r.begin(), r.end());
    ans = c != '1' ? ans + c : ans;
    cout << ans + r;
    return 0;
}