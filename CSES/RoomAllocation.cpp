#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, room = 0;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b, i});
    }
    sort(v.begin(), v.end());

    vector<int> rooms, ans(n);
    map<int, vector<int>> mp;
    for (auto &r : v)
    {
        while (mp.size() && mp.begin()->first <= r[0]) {
            auto it = mp.begin();
            while (it->second.size())
                rooms.push_back(it->second.back()), it->second.pop_back();
            mp.erase(it);
        }
        if (rooms.empty()) {
            mp[r[1] + 1].push_back(++room);
            ans[r[2]] = room;
        }
        else {
            mp[r[1] + 1].push_back(rooms.back());
            ans[r[2]] = rooms.back();
            rooms.pop_back();
        }
    }
    
    cout << room << "\n";
    for (auto &x : ans)
        cout << x << " ";
    return 0;
}