#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        vector<vector<int>> m;
        for (auto &a : v)
            if (m.empty() || a[0] > m.back()[1])
                m.push_back(a);
            else
                m.back()[1] = max(m.back()[1], a[1]);
        return m;
    }
};