#include "../../headers.h"

class Solution
{
public:
    bool winnerOfGame(string &s)
    {
        int cnta = 0, cntb = 0, a = 0, b = 0;
        s += s.back() == 'A' ? 'B' : 'A';
        for (char &c : s)
        {
            cnta += c == 'A';
            cntb += c == 'B';
            if (c == 'A')
                b += max(cntb - 2, 0), cntb = 0;
            else
                a += max(cnta - 2, 0), cnta = 0;
        }
        return a > b;
    }
};