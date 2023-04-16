#include "headers.h"

class Solution
{
public:
    vector<int> findColumnWidth(vector<vector<int>> &v)
    {
        vector<int> ans(v[0].size(), INT_MIN);
        for (int j = 0; j < v[0].size(); j++)
            for (int i = 0; i < v.size(); i++)
                ans[j] = max(ans[j], (int)to_string(v[i][j]).size());
        return ans;
    }
};