#include "../../headers.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> smap, tmap;
        for(int i = 0; i < s.length(); i++)
        {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        return smap == tmap;
    }
};