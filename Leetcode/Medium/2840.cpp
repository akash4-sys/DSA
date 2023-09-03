#include "headers.h"

class Solution
{
public:
    bool checkStrings(string s, string r)
    {   
        int odd[26] = {0}, even[26] = {0};
        for (int i = 0; i < s.size(); i++)
            if (i % 2)
                odd[s[i] - 'a']++, odd[r[i] - 'a']--;
            else
                even[s[i] - 'a']++, even[r[i] - 'a']--;

        for (int i = 0; i < 26; i++)
            if (odd[i] || even[i])
                return 0;
        return 1;
    }
};