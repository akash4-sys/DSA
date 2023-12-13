#include "../../headers.h"

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &v, int key, int k)
    {
        vector<int> ans, idx;
        for (int i = 0; i < v.size(); i++)
            if (v[i] == key)
                idx.push_back(i);
        
        for (int i = 0; i < v.size(); i++)
        {
            int j = lower_bound(idx.begin(), idx.end(), i) - idx.begin();
            if (j != idx.size() && abs(i - idx[j]) <= k)
                ans.push_back(i);
            else if (j && abs(i - idx[j - 1]) <= k)
                ans.push_back(i);
        }
        return ans;
    }
};