#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"

bool solve()
{
    int n = II;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a = II;
        while (a % 2 == 0)
            a /= 2;
        mp[a]++;
    }

    vector<int> b;
    for (int i = 0; i < n; i++) {
        int a = II;
        while (a % 2 == 0)
            a /= 2;
        if (!mp.count(a))
            b.push_back(a);
        else if (--mp[a] == 0)
            mp.erase(a);
    }

    for (int &a : b) {
        while (!mp.count(a) && a > 1)
            a /= 2;
        if (!mp.count(a))
            return 0;
        if (--mp[a] == 0)
            mp.erase(a);
    }
    return mp.size() == 0;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}