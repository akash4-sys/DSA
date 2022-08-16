#include "../../headers.h"

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> v(75, 0);
        for (char c : s)
            v[c - '0']++;

        for (int i = 0; i < s.length(); i++)
            if (v[s[i] - '0'] == 1)
                return i;
        return -1;
    }
};