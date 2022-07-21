#include "../../headers.h"

class Solution
{
public:
    int powers[7] = {1000, 500, 100, 50, 10, 5, 1};
    string romans = "MDCLXVI";
    
    string intToRoman(int n)
    {
        string ans;
        for (int i = 0; i < 7; i += 2)
        {
            int rem = n / powers[i];
            if (rem == 0)
                continue;
            if (rem <= 3)
            {
                while (rem--)
                    ans += romans[i];
            }
            else if (rem == 4)
            {
                ans += romans[i];
                ans += romans[i - 1];
            }
            else if (rem == 5)
            {
                ans += romans[i - 1];
            }
            else if (rem <= 8)
            {
                ans += romans[i - 1];
                for (int j = 5; j < rem; ++j)
                    ans += romans[i];
            }
            else
            {
                ans += romans[i];
                ans += romans[i - 2];
            }
            n %= powers[i];
        }
        return ans;
    }
};