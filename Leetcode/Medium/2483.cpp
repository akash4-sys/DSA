#include "headers.h"

class Solution
{
public:
    int bestClosingTime(string s)
    {
        vector<int> N(s.size());
        int n = 0, y = 0, ans = s.size();

        for(int i = 0; i < s.size(); i++)
            n += s[i] == 'N', N[i] = n;
        
        for(int i = s.size() - 1; i >= 0; i--)
        {
            y += s[i] == 'Y'; 
            int p = y + (i - 1 < 0 ? 0 : N[i - 1]);
            if(p <= n)
                n = p, ans = i;
        }
        return ans;
    }
};