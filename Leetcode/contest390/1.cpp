#include "../../headers.h"

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> ch(26, 0);
            for (int j = i; j < s.size(); j++) {
                if (++ch[s[j] - 'a'] > 2)
                    break;
                ans = max(ans, accumulate(ch.begin(), ch.end(), 0));
            }
        }
        return ans;
    }
};