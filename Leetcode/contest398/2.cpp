#include "../../headers.h"

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &v, vector<vector<int>> &qrs)
    {
        vector<bool> ans;
        vector<int> pf(v.size(), 0);
        for (int i = 1; i < v.size(); i++)
            pf[i] = pf[i - 1] + (v[i] % 2 == v[i - 1] % 2);
        for (auto &q : qrs)
            ans.push_back(pf[q[1]] == pf[q[0]]);
        return ans;
    }
};