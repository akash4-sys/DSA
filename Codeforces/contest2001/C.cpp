#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x = II;
    cout.flush();
    if (x == -1)
        exit(0);
    return x;
}

void print(vector<vector<int>> &edges) {
    cout << "!";
    for (auto &e : edges)
        cout << " " << e[0] << " " << e[1];
    cout << endl;
}

void solve()
{
    int n = II;
    cout.flush();

    vector<vector<int>> edges;
    for (int i = 2; i <= n; i++) {
        int l = i, r = 1;
        while (1)
        {
            int x = query(l, r);
            if (x == l) {
                edges.push_back({l, r});
                break;
            }
            r = x;
        }
    }
    print(edges);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}