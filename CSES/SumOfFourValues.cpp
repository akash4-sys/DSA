#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<vector<int>> v;
    for (int i = 0, a; i < n; i++)  {
        cin >> a;
        v.push_back({a, i + 1});
    }
    sort(v.begin(), v.end());
    
    return 0;
}