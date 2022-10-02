#include "headers.h"

class Solution
{
public:
    int xorAllNums(vector<int> &x, vector<int> &y)
    {
        int ans = INT_MIN, st = 0;
        if(x.size() % 2 == 0 && y.size() % 2 == 0)
            return 0;
        
        if(y.size() % 2 != 0)
        {
            ans = x[0];
            for(int i = 1; i < x.size(); i++)
                ans ^= x[i];
        }
        else
            ans = y[0], st = 1;
        
        if(x.size() % 2 != 0)
        {
            if(ans == INT_MIN)
                ans = y[0];
            for(int i = st; i < y.size(); i++)
                ans ^= y[i];
        }
        return ans;
    }
};