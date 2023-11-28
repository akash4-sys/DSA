#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

vector<pair<int, int>> v;

void rec(int n, int s, int t, int ax)
{
    if (n == 0)
        return;
    rec(n - 1, s, ax, t);
    v.push_back({s, t});
    rec(n - 1, ax, t, s);
}

int main()
{
    int n;
    cin >> n;
    rec(n, 1, 3, 2);
    cout << v.size() << endl;
    for (auto [s, t] : v)
        cout << s << " " << t << endl;
    return 0;
}