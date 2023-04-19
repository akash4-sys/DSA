#include "../../headers.h"

class Solution
{
public:
    string mergeAlternately(string s, string r)
    {
        string ans = "";
        for (int i = 0, j = 0, x = 1; i < s.size() || j < r.size(); x ^= 1)
            if (x && i < s.size())
                ans += s[i++];
            else if (!x && j < r.size())
                ans += r[j++];
        return ans;
    }
};