#include "../../headers.h"

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if(k > 1)
        {
            sort(begin(s), end(s));
            return s;
        }
        string r = s;
        for(int i = 1; i < s.size(); i++)
            r = min(r, s.substr(i) + s.substr(0, i));  //left rotating the string
        
        // for(int i = 1; i < s.size(); i++)
        //     s += s[0], s.erase(begin(s)), r = min(r, s);

        return r;
    }
};