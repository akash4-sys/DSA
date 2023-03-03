#include "headers.h"

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &v)
    {
        vector<int> ans;
        int sf = accumulate(v.begin(), v.end(), 0), pf = 0;
        for (int n : v)
        {
            sf -= n;
            ans.push_back(abs(sf - pf));
            pf += n;
        }
        return ans;
    }
};