#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        int n = II;
        multiset<pair<int, int>> st;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
            st.insert({II, i + 1});
        
        while (st.size() > 1)
        {
            auto [x, i] = *st.begin();
            auto [y, j] = *st.rbegin();
            st.erase(st.begin());
            if (x == 0)
                continue;

            y--, x--;
            st.erase(prev(st.end()));
            if (x != 0)
                st.insert({x, i});
            st.insert({y, j});
            ans.push_back({i, j});
        }

        cout << ans.size() << "\n";
        for (auto &r : ans)
            cout << r[0] << " " << r[1] << "\n";
    }
    return 0;
}