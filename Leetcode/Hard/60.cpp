#include "../../headers.h"

class Solution
{
    string recurse(int k, string s, int st)
    {
        if (k)
            if (st != s.size())
                for (int i = st; i < s.size(); i++)
                    swap(s[i], s[st]), recurse(k, s, st + 1);
            else k--;
        return s;
    }

public:
    string getPermutation(int n, int k)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
            s += to_string(i);
        return recurse(k - 1, s, 0);
    }
};