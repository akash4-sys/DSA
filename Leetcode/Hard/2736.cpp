#include "../../headers.h"

class Solution
{
public:
    vector<int> maximumSumQueries(vector<int> &a, vector<int> &b, vector<vector<int>> &qrs)
    {
        int n = a.size(), i = 0;
        vector<pair<int, int>> v, st;
        for (int i = 0; i < n; i++)
            v.push_back({a[i], b[i]});

        for (int i = 0; i < qrs.size(); i++)
            qrs[i].push_back(i);
        
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        sort(qrs.begin(), qrs.end(), greater<vector<int>>());

        vector<int> ans(qrs.size(), -1);
        for (auto q : qrs)
        {
            int x = q[0], y = q[1], idx = q[2];
            while (i < n && v[i].first >= x)
            {
                auto [s, r] = v[i++];
                while (st.size() && st.back().second <= s + r)
                    st.pop_back();
                if (st.empty() || st.back().first < r)
                    st.push_back({r, s + r});
            }
            auto it = lower_bound(st.begin(), st.end(), pair<int, int>{y, INT_MIN});
            ans[idx] = it == st.end() ? -1 : it->second;
        }
        return ans;
    }
};