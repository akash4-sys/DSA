#include "../../headers.h"

class Solution
{
public:
    bool canReach(string s, int x, int y)
    {
        for (int i = 0, j = 0, n = s.size(); i < n; i++)
        {
            if (i != 0 && s[i] != '2')
                continue;
            for (j = max(i + x, j); j <= min(i + y, n - 1); j++)
                if (s[j] == '0')
                    s[j] = '2';
        }
        return s.back() == '2';
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    bool canReach(string s, int x, int y)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                continue;
            for (int j = i + x; j <= i + y && j < s.size(); j++)
                if (s[j] == '0')
                    s[j] = '2';
        }
        return s.back() == '2';
    }
};