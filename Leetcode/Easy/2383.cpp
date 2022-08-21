#include "headers.h"

class Solution
{
public:
    int minNumberOfHours(int ie, int iex, vector<int> &e, vector<int> &ex)
    {
        int te = accumulate(e.begin(), e.end(), 0);
        int ans = (te >= ie) ? te - ie + 1 : 0;
        for(int exp: ex)
        {
            if(iex > exp)
                iex += exp;
            else
            {
                ans += (exp - iex + 1);
                iex += (exp - iex + 1);
                iex += exp;
            }
        }
        return ans;
    }
};