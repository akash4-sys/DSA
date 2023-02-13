#include "../../headers.h"

class Solution
{
public:
    long long countVowels(string s)
    {
        long long ans = 0, n = s.size();
        for (int i = 0; i < n; i++)
            if (string("aeiou").find(s[i]) != string::npos)
                ans += (i + 1) * (n - i);
        return ans;
    }
};