#include "../../headers.h"

class Solution
{
public:
    vector<int> xorQueries(vector<int> &v, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (int i = 1; i < v.size(); i++)
            v[i] ^= v[i - 1];
        for (auto q : queries)
            ans.push_back(q[0] ? v[q[0] - 1] ^ q[1] : v[q[1]]);
        return ans;
    }
};