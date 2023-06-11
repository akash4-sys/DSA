#include "headers.h"

class Solution
{
public:
    bool validPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j])
            {
                int l1 = i, r1 = j - 1, l2 = i + 1, r2 = j;
                for (; l1 < r1 && s[l1] == s[r1]; l1++, r1--);
                for (; l2 < r2 && s[l2] == s[r2]; l2++, r2--);
                return l1 >= r1 || l2 >= r2;
            }
        return 1;
    }
};