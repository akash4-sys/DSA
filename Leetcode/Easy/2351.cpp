#include "../../headers.h"

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> mp(256, 0);
        for(int i = 0; i < s.length(); i++)
        {
            mp[int(s[i])] += 1;
            if(mp[int(s[i])] == 2)
                return s[i];
        }
        return 'x';
    }
};