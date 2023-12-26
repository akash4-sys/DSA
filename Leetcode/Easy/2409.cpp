#include "../../headers.h"

class Solution
{
    int days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int countDays(string &s) {
        return days[(s[0] - '0') * 10 + (s[1] - '0') - 1] + (s[3] - '0') * 10 + (s[4] - '0');
    };

public:
    int countDaysTogether(string a, string al, string b, string bl)
    {
        return max(min(countDays(al), countDays(bl)) - max(countDays(a), countDays(b)) + 1, 0);
    }
};