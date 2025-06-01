#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum, a, I, J, found = 0;
    cin >> n >> sum;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (!found && mp.contains(sum - a))
            I = i, J = mp[sum - a][0], found = 1;
        if (mp[a].size() < 2)
            mp[a].push_back(i);
    }
    if (found)
        cout << I << " " << J;
    else
        cout << "IMPOSSIBLE";
    return 0;
}