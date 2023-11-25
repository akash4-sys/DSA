#include "../../headers.h"

class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long ans = 0, i = 0;
        for (int j = 0; j < s.size(); j++)
            if (s[j] == '0')
                ans += j - i, i++;
        return ans;
    }
};