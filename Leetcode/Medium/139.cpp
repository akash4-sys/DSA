#include "../../headers.h"

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<char, int> ump;
        for(char c: s)
            ump[c]++;

        for(string s: wordDict)
            for(char c: s)
                if(!ump.count(c) || !ump[c])
                    return false;
                else
                    ump[c]--;
        return true;
    }
};