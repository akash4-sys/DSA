#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

char notEq(char a, char b) {
    for (char c = 'a'; c <= 'z'; c++)
        if (c != a && c != b)
            return c;
    return 'A';
}

int main()
{
    string s;
    cin >> s;
    s += "A";
    for (int i = 1, cnt = 1; i < s.size(); i++)
    {
        cnt += s[i] == s[i - 1];
        if (s[i] != s[i - 1])
        {
            int ops = cnt / 2, j = i - (cnt % 2 ? 2 : 1);
            char c = notEq(s[i], s[i - 1]);
            for (; j >= 0 && ops; j -= 2, ops--)
                s[j] = c;
            cnt = 1;
        }
    }
    s.pop_back();
    cout << s;
    return 0;
}