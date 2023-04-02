#include "../../headers.h"

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &a, vector<int> &b, long long k)
    {
        sort(b.begin(), b.end());
        vector<int> ans;
        for (int s : a)
        {
            int i = lower_bound(begin(b), end(b), ceil((double)k / s)) - begin(b);
            ans.push_back((int)b.size() - i);
        }
        return ans;
    }
};