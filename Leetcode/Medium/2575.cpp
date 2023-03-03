#include "headers.h"

class Solution
{
public:
    vector<int> divisibilityArray(string &s, int m)
    {
        vector<int> ans;
        long long r = 0;
        for (char &c : s)
        {
            r = ((r * 10) + (c - '0')) % m;
            ans.push_back(!r);
        }
        return ans;
    }
};