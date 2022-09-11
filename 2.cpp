#include "headers.h"

class Solution
{
public:
    int partitionString(string s)
    {
        unordered_map<char, int> mp;
        for(char c: s)
            mp[c]++;
        
        int ans = 0;
        for(auto x: mp)
        {
            ans = max(ans, x.second);
        }
        return ans;
    }
};