#include "../../headers.h"

class Solution
{
public:
    bool isValid(string &s)
    {
        if (s.size() < 3)
            return 0;
        
        int vowels = 0, consonants = 0;
        string v = "aeiouAEIOU", p = "@#$";
        for (char &c : s)
        {
            if (p.find(c) != string::npos)
                return 0;
            if (isalpha(c))
                v.find(c) != string::npos ? vowels = 1 : consonants = 1;
        }
        return vowels && consonants;
    }
};