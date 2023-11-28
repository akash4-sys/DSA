#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int n;
set<string> ans;

void rec(string s, vector<int> &ch)
{
    if (s.size() == n)
    {
        ans.insert(s);
        return;
    }
    for (int c = 0; c < 26; c++)
        if (ch[c])
        {
            ch[c]--;
            rec(s + char(c + 'a'), ch);
            ch[c]++;
        }
}

int main()
{
    string s;
    cin >> s;
    n = s.size();
    vector<int> ch(26, 0);
    for (char &c : s)
        ch[c - 'a']++;

    rec("", ch);
    cout << ans.size() << endl;
    for (auto &r : ans)
        cout << r << endl;
    return 0;
}