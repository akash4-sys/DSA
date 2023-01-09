#include "headers.h"

class Solution
{
public:
    string categorizeBox(int l, int w, int h, int m)
    {
        long long v = (long)l * w * h;
        if ((v >= 1e9 || l >= 1e4 || w >= 1e4 || h >= 1e4) && (m >= 100))
            return "Both";
        else if (v >= 1e9 || l >= 1e4 || w >= 1e4 || h >= 1e4)
            return "Bulky";
        else  if (m >= 100)
            return "Heavy";
        return "Neither";
    }
};