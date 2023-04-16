#include "headers.h"

class Solution
{
public:
    vector<long long> findPrefixScore(vector<int> &v)
    {
        long long m = INT_MIN, sum = 0;
        vector<long long> ans;
        for (int n : v)
        {
            m = max(m, (long long)n);
            sum += n + m;
            ans.push_back(sum);
        }
        return ans;
    }
};