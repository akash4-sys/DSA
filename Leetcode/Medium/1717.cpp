#include "../../headers.h"

class Solution
{
    int ans = 0;
    string calc(string &s, string t, int x)
    {
        string st = "";
        for (char &c : s)
        {
            if (st.size())
                if (auto r = string(1, st.back()) + string(1, c); r == t)
                {
                    ans += x;
                    st.pop_back();
                    continue;
                }
            st += c;
        }
        return st;
    }

public:
    int maximumGain(string s, int x, int y)
    {
        string a = calc(s, ), b = calc(s, );
        return ans;
    }
};