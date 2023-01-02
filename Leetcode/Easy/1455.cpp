#include "../../headers.h"

class Solution
{
public:
    int isPrefixOfWord(string s, string w)
    {
        int j = 0, c = 1;
        for (int i = 0; i < s.size() && j < w.size(); i++)
        {
            c += s[i] == ' ';
            if (s[i] == w[j])
                j = j > 0 ? j + 1 : (!i || s[i - 1] == ' ');
            else
                j = 0;
        }
        return j == w.size() ? c : -1;
    }
};