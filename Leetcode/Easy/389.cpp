#include "../../headers.h"

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int sum = t.back();
        for (int i = 0; i < s.size(); i++)
            sum += t[i] - s[i];
        return (char)sum;
    }
};