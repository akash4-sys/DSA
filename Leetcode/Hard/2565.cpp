#include "../../headers.h"

class Solution
{
public:
    int minimumScore(string s, string t)
    {
        int sz = s.size(), tz = t.size(), k = tz - 1;
        vector<int> sf(tz, -1);
        for (int i = sz - 1; i >= 0 && k >= 0; i--)
            if (s[i] == t[k])
                sf[k--] = i;
        
        int ans = k + 1;
        for (int i = 0, j = 0; i < sz && j < tz && ans > 0; i++)
            if (s[i] == t[j])
            {
                for (; k < t.size() && sf[k] <= i; k++);
                ans = min(ans, k - (++j));
            }
        return ans;
    }
};