#include "../../headers.h"

class Solution
{
public:
    bool isAlienSorted(vector<string> &v, string r)
    {
        int ch[26] = {0};
        for (int i = 0; i < r.size(); i++)
            ch[r[i] - 'a'] = i;
        
        for (auto &w : v)
            for (char &c : w)
                c = ch[c - 'a'];
        return is_sorted(v.begin(), v.end());
    }
};