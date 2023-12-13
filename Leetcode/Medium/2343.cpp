#include "../../headers.h"

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &v, vector<vector<int>> &qrs)
    {
        int len = v[0].size();
        vector<int> ans;
        for (auto &q : qrs)
        {
            multiset<pair<string, int>> st;
            for (int i = 0; i < v.size(); i++)
            {
                string s = "";
                for (int j = len - q[1]; j < len; j++)
                    s += v[i][j];
                st.insert({s, i});
            }

            auto it = st.begin();
            for (; q[0] > 1; q[0]--, it++);
            ans.push_back(it->second);
        }
        return ans;
    }
};