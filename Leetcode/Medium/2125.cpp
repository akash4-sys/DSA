#include "../../headers.h"

class Solution
{
public:
    int numberOfBeams(vector<string> &v)
    {
        int p = 0, ans = 0;
        for (auto &s : v)
        {
            int ones = count(s.begin(), s.end(), '1');
            if (ones != 0)
                ans = p ? ans + (p * ones) : ans, p = ones;
        }
        return ans;
    }
};