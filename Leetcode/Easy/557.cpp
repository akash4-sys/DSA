#include "../../headers.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        string ans, t = " ";
        for(char c: s)
        {
            if(c == ' ')
                reverse(t.begin(), t.end()), ans += t, t = "";
            t += c;
        }
        reverse(t.begin(), t.end());
        ans += t;
        ans.pop_back();
        return ans;
    }
};