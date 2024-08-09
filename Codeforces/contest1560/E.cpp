#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

string solve()
{
    string t, op = "";
    cin >> t;
    int n = t.size(), cnt[26] = {0}, *ch = cnt - 'a', m = 0;
    for (int i = n - 1; i >= 0; i--)
        if (++ch[t[i]] == 1)
            op += t[i];
    
    reverse(op.begin(), op.end());
    for (int i = 0; i < op.size(); i++)
        m += (ch[op[i]] / (i + 1));
    
    string s = t.substr(0, m), r = s;
    for (char &del : op)
    {
        string new_s = "";
        for (char &c : s)
            if (c != del)
                new_s += c, r += c;
        s = new_s;
    }
    if (r == t)
        return t.substr(0, m) + " " + op;
    return "-1";
}

int main()
{
    fast;
    int t;
        cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}