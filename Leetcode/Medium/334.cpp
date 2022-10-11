#include "../../headers.h"

class Solution
{
public:
    bool increasingTriplet(vector<int> &v)
    {
        int x = INT_MAX, y = INT_MAX;
        for(auto n: v)
        {
            if(n <= x)
                x = n;
            else if(n <= y)
                y = n;
            else return true;
        }
        return false;
    }
};