#include "headers.h"

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &pos, vector<int> &hlt, string dirs)
    {
        vector<int> ans, rh(pos.size(), 0);
        vector<vector<int>> v, st;
        unordered_map<int, int> mp;

        for (int i = 0; i < pos.size(); i++)
        {
            v.push_back({pos[i], hlt[i], dirs[i] == 'R'});
            mp[pos[i]] = i;
        }
        
        sort(v.begin(), v.end());
        for (auto r : v)
        {
            int p = r[0], h = r[1], d = r[2];
            while (st.size() && st.back()[2] && !d && st.back()[1] < h)
                st.pop_back(), h--;

            if (st.size() && st.back()[2] && !d && st.back()[1] == h) {
                st.pop_back();
                continue;
            }

            if (st.size() && st.back()[2] && !d && st.back()[1] > h) {
                st.back()[1]--;
                continue;
            }
            st.push_back({p, h, d});
        }
        
        for (auto r : st)
            rh[mp[r[0]]] = r[1];
        
        for (int r : rh)
            if (r != 0)
                ans.push_back(r);
        return ans;
    }
};