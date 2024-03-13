#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    string s;
    cin >> s;
    long long w = 0, o = 0, ans = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'o')
            o += w;
        else if (i && s[i - 1] == 'v')
            w++, ans += o;
    cout << ans;
    return 0;
}