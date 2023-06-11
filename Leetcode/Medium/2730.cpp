#include "headers.h"

class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int ans = 1, last = 0;
        for (int i = 0, j = 1; j < s.size(); j++)
        {
            if (s[j] == s[j - 1])
                i = last, last = j;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};