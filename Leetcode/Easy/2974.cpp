#include "../../headers.h"

class Solution
{
public:
    vector<int> numberGame(vector<int> &v)
    {
        vector<int> ans(v.size(), 0);
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i += 2)
            ans[i] = v[i - 1], ans[i - 1] = v[i];
        return ans;
    }
};