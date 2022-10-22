#include "../../headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(1)
class Solution 
{
public:
    int countConsistentStrings(string s, vector<string>& v) 
    {
        int ch = 0, ans = v.size();
        for(char c: s)
            ch |= (1 << (c - 'a'));
        for(string r: v)
            for(char c: r)
                if((1 & (ch >> (c - 'a'))) == 0)
                {
                    ans--;
                    break;
                }
        return ans;
    }
};