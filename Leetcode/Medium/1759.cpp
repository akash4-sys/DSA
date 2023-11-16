#include "../../headers.h"

class Solution
{
public:
    int countHomogenous(string &s)
    {
        int ans = 0, cnt = 0, p = 0, mod = 1e9 + 7;
        for (char &c : s)
        {
            cnt = p == c ? cnt + 1 : 1;
            p = c;
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};