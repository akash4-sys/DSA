#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })

int main()
{
    int n = II;
    string s = SS, t = SS;
    vector<int> ab, ba;
    for (int i = 0; i < n; i++)
        if (s[i] == 'a' && t[i] == 'b')
            ab.push_back(i);
        else if (s[i] == 'b' && t[i] == 'a')
            ba.push_back(i);
    
    if ((ab.size() + ba.size()) % 2) {
        cout << "-1";
        return 0;
    }

    vector<vector<int>> ans;
    for (int i = 0; i < ab.size(); i += 2)
        if (i + 1 < ab.size())
            ans.push_back({ab[i], ab[i + 1]});
    for (int i = 0; i < ba.size(); i += 2)
        if (i + 1 < ba.size())
            ans.push_back({ba[i], ba[i + 1]});
    
    if (ab.size() % 2) {
        ans.push_back({ab.back(), ab.back()});
        ans.push_back({ba.back(), ab.back()});
    }

    cout << ans.size() << "\n";
    for (auto &idx : ans)
        cout << idx[0] + 1 << " " << idx[1] + 1 << "\n";
    return 0;
}