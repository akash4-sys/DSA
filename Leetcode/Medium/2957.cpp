#include "../../headers.h"

class Solution
{
public:
    int removeAlmostEqualCharacters(string &s)
    {
        int ans = 0;
        for (int i = 1; i < s.size(); i++)
            if (abs(s[i] - s[i - 1]) <= 1)
                ans++, i++;
        return ans;
    }
};