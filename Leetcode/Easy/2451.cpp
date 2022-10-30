#include "headers.h"

class Solution
{
public:
    string oddString(vector<string> &words)
    {
        unordered_map<string, int> ump;
        unordered_map<string, string> ch;
        for(string s: words)
        {
            string r;
            for(int i = 0; i < s.length() - 1; i++)
                r += to_string(s[i + 1] - s[i]) + "_";
            ump[r]++;
            ch[r] = s;
        }
        for(auto [s, c]: ump)
            if(c == 1)
                return ch[s];
        return "";
    }
};