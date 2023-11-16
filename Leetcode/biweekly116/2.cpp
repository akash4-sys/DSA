#include "../../headers.h"

class Solution
{
public:
    int minChanges(string &s)
    {
        int one = 0, zero = 0, ans = 0;
        for (char &c : s)
        {
            one += c == '1';
            zero += c == '0';
            if (c == '1' && zero % 2)
                ans++, one--, zero = 0;
            else if (c == '0' && one % 2)
                ans++, zero--, one = 0;
        }
        return ans;
    }
};