#include "../../headers.h"

class Solution
{
    string ans = "1";
public:
    string countAndSay(int n)
    {
        if(n == 1)
            return ans;
        
        int i = 0, j, len = ans.size();
        string s = "";
        while(i < len)
        {
            j = i;
            while(i < len && ans[i] == ans[j])
                i++;
            s += to_string(i - j) + ans[j];
        }
        ans = s;
        return countAndSay(n-1);
    }
};