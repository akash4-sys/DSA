#include "headers.h"

class Solution
{
public:
    int mostFrequentEven(vector<int> &v)
    {
        map<int, int> mp;
        for(int n: v)
            if(n % 2 == 0)
                mp[n]++;

        if(!mp.size())
            return -1;
        
        int ans, f = 0;
        for(auto x: mp)
            if(x.second > f)
                ans = x.first, f = x.second;

        return ans;
    }
};