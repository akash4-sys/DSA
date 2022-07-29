#include "../../headers.h"

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int open = 0, close = 0, ans = 0, rclose = 0, ropen = 0;
        int i = 0, j = s.length() - 1;

        while(i < s.length())
        {
            open += s[i] == '(';
            close += s[i] == ')';

            ropen += s[j] == '(';
            rclose += s[j] == ')';

            if(ropen == rclose)
                ans = max(ans, ropen*2);
            if(open == close)
                ans = max(ans, open*2);

            if(ropen > rclose)
                ropen = rclose = 0;
            if(close > open)
                open = close = 0;
                
            i++;
            j--;
        }
        return ans;
    }
};