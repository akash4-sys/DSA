#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a ; a; })

int query(int u) {
    cout << "? 1 1 " << u << endl;
    return II;
}

void toggle(int u) { cout << "? 2 " << u << endl; }

void print(vector<int> &val) {
    cout << "! ";
    for (int i = 1; i < val.size(); i++) cout << val[i] << " ";
    cout << endl;
}

void solve()
{
    int n = II;
    for (int m = n - 1; m; m--)
        II, II;

    int f1 = query(1);
    if (abs(f1) == 1) {
        vector<int> v(n + 1, f1);
        for (int i = 2; i <= n; i++)
            v[i] = query(i) - f1;
        print(v);
        return;
    }

    if (f1 != 0)
        toggle(1);

    int rootVal = 10;
    vector<int> v(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        v[i] = query(i);
        if (abs(v[i]) == 1)
            rootVal = v[i];
    }
    v[1] = f1 - rootVal;
    print(v);
}

int main()
{
    fast;
    for (int t = II; t; t--)
        solve();
    return 0;
}