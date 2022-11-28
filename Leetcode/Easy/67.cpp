#include "../../headers.h"

class Solution
{
public:
    string addBinary(string s, string r)
    {
        string ans = "";
        int c = 0, i = s.size() - 1, j = r.size() - 1;
        while (i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? s[i--] - '0' : 0;
            c += j >= 0 ? r[j--] - '0' : 0;
            cout<<char(c % 2 + '0')<<" ";
            ans = char(c % 2 + '0') + ans;
            c /= 2;
        }
        return ans;
    }
};