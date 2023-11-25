#include "../../headers.h"

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &h, vector<vector<int>> &q)
    {
        vector<int> ans(q.size()), st, idx;
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i][0] > q[i][1])
                swap(q[i][0], q[i][1]);
            if (q[i][0] == q[i][1] || h[q[i][0]] < h[q[i][1]])
                ans[i] = q[i][1];
            else
                idx.push_back(i);
        }
        
        sort(idx.begin(), idx.end(), [&](int &i, int &j){
            return q[i][1] > q[j][1];
        });

        int j = h.size() - 1;
        for (int i : idx)
        {
            while (j > q[i][1])
            {
                while (st.size() && h[st.back()] <= h[j])
                    st.pop_back();
                st.push_back(j--);
            }

            auto it = upper_bound(st.rbegin(), st.rend(), q[i][0], [&](int x, int y){
                return h[x] < h[y];
            });
            ans[i] = it == st.rend() ? -1 : *it;
        }
        return ans;
    }
};