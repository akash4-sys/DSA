#include "headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int ans = 0, o = 0, z = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                z = o ? 1 : z + 1;
            o = s[i] == '0' ? 0 : o + 1;
            ans = max(ans, min(o, z) * 2);
        }
        return ans;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '0')
            {
                int o = 0, z = 0;
                for (; i < s.size() && s[i] == '0'; i++, o++);
                for (; i < s.size() && s[i] == '1'; i++, z++);
                ans = max(ans, min(o, z) * 2);
                i--;
            }
        return ans;
    }
};