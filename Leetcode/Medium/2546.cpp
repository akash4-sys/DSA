#include "headers.h"

class Solution
{
public:
    bool makeStringsEqual(string s, string t)
    {
        return (s.find('1') != string::npos) == (t.find('1') != string::npos);
    }
};


class Solution
{
public:
    bool makeStringsEqual(string s, string t)
    {
        int x = 0, y = 0;
        for (int i = 0; i < s.length(); i++)
        {
            x |= s[i] == '1';
            y |= t[i] == '1';
        }
        return x == y;
    }
};