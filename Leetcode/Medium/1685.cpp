#include "../../headers.h"

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &v)
    {
        int sum = accumulate(v.begin(), v.end(), 0), n = v.size();
        vector<int> ans(n);
        for (int i = 0, csum = 0; i < n; i++)
        {
            ans[i] = sum - (v[i] * (n - i)) + (v[i] * i) - csum;
            sum -= v[i];
            csum += v[i];
        }
        return ans;
    }
};