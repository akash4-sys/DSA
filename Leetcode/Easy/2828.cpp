#include "../headers.h"

class Solution
{
public:
    bool isAcronym(vector<string> &words, string s)
    {
        string temp = "";
        for (auto &r: words)
            temp += r[0];
        return temp == s;
    }
};