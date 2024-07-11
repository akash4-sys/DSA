#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

void input(vv &v) {
    for (auto &r : v) {
        string s;
        cin >> s;
        for (char &c : s)
            r.push_back(c - '0');
    }
}

bool solve()
{
    int n = II, m = II;
    vv a(n), b(n);
    input(a);
    input(b);

    for (int i = 0; i < n; i++) {
        int asum = 0, bsum = 0;
        for (int j = 0; j < m; j++)
            (asum += a[i][j]) %= 3, (bsum += b[i][j]) %= 3;
        if (asum != bsum)
            return 0;
    }

    for (int j = 0; j < m; j++) {
        int asum = 0, bsum = 0;
        for (int i = 0; i < n; i++)
            (asum += a[i][j]) %= 3, (bsum += b[i][j]) %= 3;
        if (asum != bsum)
            return 0;
    }
    return 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}