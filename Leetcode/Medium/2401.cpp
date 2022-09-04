#include "headers.h"

class Solution
{
public:
    int longestNiceSubarray(vector<int> &v)
    {
        int ans = 1, curr = v[0], j = 0;
        for (int i = 1; i < v.size(); i++)
        {
            while((curr & v[i]) != 0)
                curr -= v[j++];
            ans = max(ans, i - j + 1);
            curr += v[i];
        }
        return ans;
    }
};