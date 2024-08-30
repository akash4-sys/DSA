#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })

const string Pairs[6] = {"BR", "BG", "BY", "GR", "GY", "RY"};

int key(string s) {
    for (int i = 0; i < 6; i++)
        if (Pairs[i] == s)
            return i;
    return -1;
}

int isPath(string s, string r) {
    return s[0] == r[0] || s[1] == r[0] || s[0] == r[1] || s[1] == r[1];
}

void solve()
{
    int n = II, q = II;
    vector<string> v(n + 1);
    vector<set<int>> nodes(6);
    for (int i = 1; i <= n; i++) {
        v[i] = SS;
        sort(all(v[i]));
        nodes[key(v[i])].insert(i);
    }

    while (q--)
    {
        int x = II, y = II;
        if (isPath(v[x], v[y]))
            cout << abs(x - y) << "\n";
        else
        {
            int ans = INT_MAX;
            for (auto &S : Pairs)
                if (S != v[x] && isPath(v[x], S))
                {
                    int i = key(S);
                    auto it = nodes[i].upper_bound(x);
                    if (it != nodes[i].end())
                        ans = min(ans, abs(*it - x) + abs(*it - y));
                    if (it != nodes[i].begin()) {
                        it = prev(it);
                        ans = min(ans, abs(*it - x) + abs(*it - y));
                    }
                }
            cout << (ans == INT_MAX ? -1 : ans) << "\n";
        }
    }
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}