#include <bits/stdc++.h>
using namespace std;

int query(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << " " << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    int n, j = 0;
    cin >> n;
    vector<int> ans(n, -1);
    for (int i = 1; i < n; i++) {
        int a = query(j, i), b = query(i, j);
        if (a > b)
            ans[j] = a, j = i;
        else
            ans[i] = b;
    }

    ans[j] = n;
    cout << "! ";
    for (int &a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}