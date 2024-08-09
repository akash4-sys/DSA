#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ long long a; cin>>a; a; })

char solve()
{
    string s, r = "";
    cin >> s;
    long long p = LL, n = s.size(), k = 0;
    for (; p > n - k; k++)
        p -= (n - k);
    
    for (char &c : s)
    {
        while (r.size() && k && r.back() > c)
            r.pop_back(), k--;
        r += c;
    }
    return r[p - 1];
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve();
    return 0;
}