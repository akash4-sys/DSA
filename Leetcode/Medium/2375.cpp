#include "../../headers.h"

class Solution
{
public:
    string smallestNumber(string p)
    {
        string ans = "";
        stack<int> s;
        if (p[0] == 'I') ans += '1';
        else s.push('1');
        
        int i = 1;
        while(i < p.length())
        {
            if(p[i-1] == 'I')
                while(!s.empty())
                    ans += s.top(), s.pop();
            s.push('0' + i + 1);
        }

        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};