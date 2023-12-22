#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &v, int k)
    {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for (int i = 2; i < v.size();)
            if (v[i] - v[i - 2] <= k)
                ans.push_back({v[i - 2], v[i - 1], v[i]}), i += 3;
            else
                return {};
        return ans;
    }
};