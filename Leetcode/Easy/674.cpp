#include "headers.h"

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &v)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int c = 1;
            for (int j = i + 1; j < v.size() && v[j] > v[j - 1]; j++)
                c += v[j] > v[j - 1];
            ans = max(ans, c);
        }
        return ans;
    }
};