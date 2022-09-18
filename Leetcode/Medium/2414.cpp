#include "headers.h"

class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int ans = 1, len = 1;
        for(int i = 1; i < s.length(); i++)
        {
            len = (s[i] - s[i - 1] == 1) ? len + 1 : 1;
            ans = max(ans, len);
        }
        return ans;
    }
};