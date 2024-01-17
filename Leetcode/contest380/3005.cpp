#include "../../headers.h"

class Solution
{
public:
    int maxFrequencyElements(vector<int> &v)
    {
        int mxf = 0, ans = 0;
        unordered_map<int, int> mp;
        for (int a : v)
            mxf = max(mxf, ++mp[a]);
        
        for (auto &[n, c] : mp)
            if (c == mxf)
                ans += c;
        return ans;
    }
};