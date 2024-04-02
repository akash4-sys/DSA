#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

vector<int> colorStr(string &s, int n)
{
    vector<int> color(n, 0);
    for (int l = 0, r = 0; l < n; l++)
        if (s[l] == ')')
            r = max(r, l + 1);
        else
        {
            for (; r < n && s[r] != ')'; r++);
            if (r < n)
                color[l] = color[r] = 1;
            r++;
        }
    return color;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int open = count(s.begin(), s.end(), '(');
    if (open != n - open) {
        cout << -1 << endl;
        return;
    }

    vector<int> a = colorStr(s, n);
    reverse(s.begin(), s.end());
    vector<int> b = colorStr(s, n);

    int azero = count(a.begin(), a.end(), 0);
    int bzero = count(b.begin(), b.end(), 0);
    int ac = (azero > 0 && azero < n) + 1;
    int bc = (bzero > 0 && bzero < n) + 1;

    if (ac > bc)
        swap(a, b), swap(ac, bc);
    
    cout << ac << endl;
    for (int col : a)
        cout << (col ? col : ac) << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}