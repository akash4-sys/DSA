#include "../../headers.h"

class Solution
{
public:
    int countTime(string t)
    {
        int ans = 1;
        if (t[0] == '?')
            ans = t[1] == '?' ? 24 : t[1] < '4' ? 3 : 2;
        else if (t[1] == '?')
            ans = t[0] < '2' ? 10 : 4;
        return ans * (t[3] == '?' ? 6 : 1) * (t[4] == '?' ? 10 : 1);
    }
};