#include "../../headers.h"

class Solution
{
public:
    vector<long long> minOperations(vector<int> &v, vector<int> &q)
    {
        sort(v.begin(), v.end());
        vector<long long> ans, pf = {0};
        for (int n : v)
            pf.push_back(pf.back() + n);
        
        for (long long n : q)
        {
            int i = lower_bound(v.begin(), v.end(), n) - v.begin();
            long long x = (i * n) - pf[i];
            long long y = (pf.back() - pf[i]) - ((v.size() - i) * n);
            ans.push_back(x + y);
        }
        return ans;
    }
};