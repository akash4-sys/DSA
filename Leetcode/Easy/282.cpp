#include "../../headers.h"

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &v)
    {
        v.push_back(INT_MIN);
        vector<string> ans;
        for (int i = 0, l = v[0]; i < v.size() - 1; i++)
            if (v[i] == INT_MAX || v[i] + 1 != v[i + 1])
            {
                string s = to_string(l);
                s += v[i] == l ? "" : "->" + to_string(v[i]);
                ans.push_back(s);
                l = v[i + 1];
            }
        return ans;
    }
};