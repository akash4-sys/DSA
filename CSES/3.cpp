#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char p = s[0];
    int ans = 0, cnt = 0;
    for (char &c : s)
    {
        if (c == p)
            ans = max(ans, ++cnt);
        else
            p = c, cnt = 1;
    }
    cout << ans;
    return 0;
}