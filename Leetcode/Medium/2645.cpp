#include "headers.h"

class Solution
{
public:
    int addMinimum(string s)
    {
        int k = 0, prev = 'z';
        for (char c : s)
        {
            k += c <= prev;
            prev = c;
        }
        return (k * 3) - s.size();
    }
};

class Solution
{
public:
    int addMinimum(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size();)
        {
            s[i] == 'a' ? i++ : ans++;
            s[i] == 'b' ? i++ : ans++;
            s[i] == 'c' ? i++ : ans++;
        }
        return ans;
    }
};