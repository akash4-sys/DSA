#include "headers.h"

class Solution
{
public:
    int firstCompleteIndex(vector<int> &v, vector<vector<int>> &m)
    {
        vector<int> it(v.size() + 1);
        for (int i = 0; i < v.size(); i++)
            it[v[i]] = i;
        
        int ans = INT_MAX;
        for (auto &r : m)
        {
            int x = INT_MIN;
            for (int &a : r)
                x = max(x, a);
            ans = min(ans, x);
        }
        
        for (int j = 0; j < m[0].size(); j++)
        {
            int x = INT_MIN;
            for (int i = 0; i < m.size(); i++)
                x = max(x, it[m[i][j]]);
            ans = min(ans, x);
        }
        return ans;
    }
};