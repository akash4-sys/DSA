#include "../../headers.h"

class Solution
{
public:
    vector<bool> canEat(vector<int> &v, vector<vector<int>> &qrs)
    {
        vector<long long> pf(1, 0);
        for (int a : v)
            pf.push_back(pf.back() + a);
        
        vector<bool> ans;
        for (auto &q : qrs)
        {
            long long type = q[0], favDay = q[1], cap = q[2];
            long long maxCandies = (favDay + 1) * cap;
            ans.push_back(pf[type + 1] > favDay && pf[type] < maxCandies);
        }
        return ans;
    }
};