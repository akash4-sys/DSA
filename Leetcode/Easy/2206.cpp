#include "../../headers.h"

class Solution 
{
public:
    bool divideArray(vector<int>& v) 
    {
        unordered_map<int, int> ump;
        for(int n: v)
            ump[n]++;
        for(auto &[x, y]: ump)
            if(y % 2)
                return false;
        return true;
    }
};