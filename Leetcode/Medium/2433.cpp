#include "headers.h"

class Solution
{
public:
    vector<int> findArray(vector<int> &v)
    {
        vector<int> ans = {v[0]};
        for(int i = 1; i < v.size(); i++)
            ans.push_back(v[i] ^ v[i - 1]);
        return ans;
    }
};