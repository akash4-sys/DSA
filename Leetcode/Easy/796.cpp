#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)
class Solution
{
public:
    bool rotateString(string s, string r)
    {
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[0];
            s.erase(s.begin());
            s += c;
            if (s == r)
                return 1;
        }
        return 0;
    }
};