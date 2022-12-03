#include "../../headers.h"

class Solution
{
    bool isVowel(char &c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

public:
    bool halvesAreAlike(string s)
    {
        int v = 0, mid = s.size() / 2;
        for (int i = 0; i < mid; i++)
            v += isVowel(s[i]) - isVowel(s[mid + i]);
        return !v;
    }
};