#include "../../headers.h"

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int ones = 0, zero = count(s.begin(), s.end(), '0'), ans = zero;
        for (int i = 0; i < s.size(); i++)
        {
            ans = min(ans, ones + zero);
            ones += s[i] == '1';
            zero -= s[i] == '0';
        }
        return min(ans, ones);
    }
};