#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<int> rec(long long x) {
    vector<int> res;
    if (x == 2)
        res.push_back(0);
    else if (x % 2) {
        res = rec(x - 1);
        res.push_back(*min_element(res.begin(), res.end()) - 1);
    }
    else {
        res = rec(x / 2);
        res.push_back(*max_element(res.begin(), res.end()) + 1);
    }
    return res;
}

void solve()
{
    long long x;
    cin >> x;
    auto ans = rec(x);
    cout << ans.size() << "\n";
    for (auto &a : ans)
        cout << a << " ";
    cout << "\n";
}

int main()
{
    fast;
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}