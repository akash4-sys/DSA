#include "headers.h"

class Solution
{
    bool equal(int mp1[], int mp2[])
    {
        int x = 0, y = 0;
        for (int i = 0; i < 26; i++)
            x += mp1[i] != 0, y += mp2[i] != 0;
        return x == y;
    }

public:
    bool isItPossible(string s, string r)
    {
        int mp1[26] = {0}, mp2[26] = {0};
        for (char c : s)
            mp1[c - 'a']++;
        for (char c: r)
            mp2[c - 'a']++;
        
        for (int i = 0; i < 26; i++)
        {
            if (!mp1[i])
                continue;
            for (int j = 0; j < 26; j++)
            {
                if (!mp2[j])
                    continue;
                mp1[i]--, mp2[i]++, mp2[j]--, mp1[j]++;  //swap
                if (equal(mp1, mp2))
                    return 1;
                mp1[i]++, mp2[i]--, mp2[j]++, mp1[j]--;  //unswap
            }
        }
        return 0;
    }
};