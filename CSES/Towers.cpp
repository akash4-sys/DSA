#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        int j = upper_bound(v.begin(), v.end(), a) - v.begin();
        if (j == v.size())
            v.push_back(a);
        else
            v[j] = a;
    }
    cout << v.size();
    return 0;
}