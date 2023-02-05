#include "headers.h"

class Solution
{
    unordered_map<char, int> mp = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
public:
    vector<int> vowelStrings(vector<string> &v, vector<vector<int>> &qrs)
    {
        vector<int> ans, p(v.size(), 0);
        p[0] = (mp.count(v[0][0]) && mp.count(v[0].back()));
        for (int i = 1; i < v.size(); i++)
            p[i] = p[i - 1] +  (mp.count(v[i][0]) && mp.count(v[i].back()));
        
        for (auto q: qrs)
            ans.push_back(p[q[1]] - (q[0] ? p[q[0] - 1] : 0));
        return ans;
    }
};