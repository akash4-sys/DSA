#include "../../headers.h"

class Solution
{
public:
    bool canMakeSubsequence(string s, string p)
    {
        int j = 0;
        if (s.size() < p.size())
            return 0;
        for (int i = 0; i < s.size() && j < p.size(); i++)
            if (s[i] == p[j] || (p[j] == char((((s[i] - 'a') + 1) % 26) + 'a')))
                j++;
        return j == p.size();
    }
};