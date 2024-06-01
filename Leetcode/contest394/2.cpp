#include "../../headers.h"

class Solution {
public:
    int numberOfSpecialChars(string s) {
        int l[26] = {0}, u[26] = {0};
        memset(l, -1, sizeof(l));
        memset(u, -1, sizeof(u));
        for (int i = 0; i < s.size(); i++)
            if (islower(s[i]))
                l[s[i] - 'a'] = i;
            else {
                if (u[s[i] - 'A'] == -1)
                    u[s[i] - 'A'] = i;
            }
        
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += (l[i] < u[i] && l[i] != -1);
        return cnt;
    }
};