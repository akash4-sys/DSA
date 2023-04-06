#include "headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    int partitionString(string s)
    {
        int ch[26] = {0}, ans = 1;
        for (char &c : s)
        {
            if (ch[c - 'a'] + 1 == 2)
                memset(ch, 0, sizeof(ch)), ans++;
            ch[c - 'a']++;
        }
        return ans;
    }
};