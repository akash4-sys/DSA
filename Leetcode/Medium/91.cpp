#include "../../headers.h"

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0' || !s.size())
            return 0;

        int ans = 1, last = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if(s[i] == '0')
                ans = 0;
            if(s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6')
            {
                ans += last;
                last = ans - last;
            }
            else
                last = ans;
        }
        return ans;
    }
};