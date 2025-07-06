#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define CC ({ char a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << "\n"

string solve()
{
    int n = II, qrs = II;
    string s = SS;
    vector<vector<set<int>>> q(3, vector<set<int>>(3));
    for (int i = 0; i < qrs; i++) {
        char x = CC, y = CC;
        if (x != y && x != 'a')
            q[x - 'a'][y - 'a'].insert(i);
    }

    for (auto &c : s) {
        if (c == 'b')
        {
            if (!q[1][0].empty())
                q[1][0].erase(q[1][0].begin()), c = 'a';
            else if (!q[1][2].empty()) {
                auto &ca = q[2][0];
                auto it = ca.lower_bound(*q[1][2].begin());
                if (it != ca.end()) {
                    q[1][2].erase(q[1][2].begin());
                    ca.erase(it);
                    c = 'a';
                }
            }
        }
        if (c == 'c')
        {
            if (!q[2][0].empty())
                q[2][0].erase(q[2][0].begin()), c = 'a';
            else if (!q[2][1].empty()) {
                auto &ba = q[1][0];
                auto it = ba.lower_bound(*q[2][1].begin());
                q[2][1].erase(q[2][1].begin());
                c = 'b';
                if (it != ba.end()) {
                    ba.erase(it);
                    c = 'a';
                }
            }
        }
    }
    return s;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}