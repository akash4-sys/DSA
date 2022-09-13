#include "../../headers.h"

class Solution
{
public:
    int getMaxLen(vector<int> &v)
    {
        int ans = 0, p = 0, n = 0;
        for(int num: v)
        {
            if(num > 0)
                n += (n != 0), p++;
            else if(num < 0)
            {
                int temp = p;
                p = n ? n + 1 : 0;
                n = temp + 1;
            }
            else
                p = n = 0;
            ans = max(ans, p);
        }
        return ans;
    }
};