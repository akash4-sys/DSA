#include "../../headers.h"

class Solution
{
public:
    vector<int> findPeaks(vector<int> &v)
    {
        vector<int> ans;
        for (int i = 1; i < v.size() - 1; i++)
            if (v[i] > v[i - 1] && v[i] > v[i + 1])
                ans.push_back(i);
        return ans;
    }
};