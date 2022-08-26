#include "../../headers.h"

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        for(int i = 0; i <= 29; i++)
        {
            string r = to_string(1 << i);
            sort(r.begin(), r.end());
            if(r == s)
                return true;
        }
        return false;
    }
};