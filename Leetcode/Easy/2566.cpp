#include "headers.h"

class Solution
{
    int num(string &s, char x, int d)
    {
        int n = 0;
        for (char &c : s)
            n = (n * 10) + (c == x ? d : c - '0');
        return n;
    }

public:
    int minMaxDifference(int n)
    {
        string s = to_string(n);
        int i = 0;
        for (; i < s.size() && s[i] == '9'; i++);
        char c = i == s.size() ? 'a' : s[i];
        return abs(num(s, c, 9) - num(s, s[0], 0));
    }
};