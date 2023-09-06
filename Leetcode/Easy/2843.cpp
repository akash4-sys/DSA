#include "headers.h"

class Solution
{
public:
    int countSymmetricIntegers(int l, int r)
    {
        int ans = 0;
        for (; l <= r; l++)
        {
            string s = to_string(l);
            int sum = 0, n = s.size();
            for (int i = 0; i < n / 2 && n % 2 == 0; i++)
                sum += (s[i] - '0') - (s[n - i - 1] - '0');
            ans += !sum && n % 2 == 0;
        }
        return ans;
    }
};