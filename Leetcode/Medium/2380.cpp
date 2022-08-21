#include "headers.h"

class Solution
{
public:
    int secondsToRemoveOccurrences(string s)
    {
        int sec = 0, zeros = 0;
        for (char c: s)
        {
            zeros += c == '0';
            if(c == '1' && zeros)
                sec = max(sec + 1, zeros);
        }
        return sec;
    }
};