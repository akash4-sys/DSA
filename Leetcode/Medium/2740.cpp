#include "headers.h"

class Solution
{
public:
    int findValueOfPartition(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int ans = INT_MAX;
        for (int i = 1; i < v.size(); i++)
            ans = min(ans, v[i] - v[i - 1]);
        return ans;
    }
};