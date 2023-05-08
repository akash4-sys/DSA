#include "../../headers.h"

class Solution
{
public:
    string predictPartyVictory(string s)
    {
        queue<int> r, d;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'R')
                r.push(i);
            else
                d.push(i);
        
        while (!r.empty() && !d.empty())
        {
            int ri = r.front(), di = d.front();
            r.pop(), d.pop();
            if (ri < di)
                r.push(ri + s.size());
            else
                d.push(di + s.size());
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};