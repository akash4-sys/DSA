#include "headers.h"

class Solution
{
public:
    vector<int> separateDigits(vector<int> &v)
    {
        vector<int> res;
        for (int n : v)
        {
            string snum = to_string(n);
            for (char c : snum)
                res.push_back(c - '0');
        }
        return res;
    }
};