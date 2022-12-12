#include "headers.h"

class Solution
{
public:
    int maximumValue(vector<string> &v)
    {
        int ans = 0;
        for(auto s: v)
        {
            int ch = 0;
            for(char c: s)
                if(isalpha(c))
                {
                    ch = 1;
                    break;
                }
            int x = ch == 1 ? s.size() : stoi(s);
            ans = max(ans, x);
        }
        return ans;
    }
};