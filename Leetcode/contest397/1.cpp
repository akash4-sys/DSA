#include "../../headers.h"

class Solution
{
public:
    int findPermutationDifference(string s, string t)
    {
        int ch[26] = {0}, ans = 0;
        for (int i = 0; i < s.size(); i++)
            ch[s[i] - 'a'] = i;
        for (int i = 0; i < t.size(); i++)
            ans += abs(ch[t[i] - 'a'] - i);
        return ans;
    }
};