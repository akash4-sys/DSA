#include "headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    int partitionString(string s)
    {
        vector<int> mp(26, 0);
        int ans = 1;
        for(char c: s)
        {
            if(mp[c - 'a'] != 0)
            {
                mp = vector<int>(26, 0);
                ans++;
            }
            mp[c - 'a']++;
        }
        return ans;
    }
};