#include "../../headers.h"

class Solution 
{
public:
    bool containsDuplicate(vector<int>& v) 
    {
        unordered_map<int, int> ump;
        for(int n: v)
            if(++ump[n] >= 2)
                return true;
        return false;
    }
};