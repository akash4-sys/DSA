#include "headers.h"

class Solution
{
    bool rec(string &s, int k, int i, int sum)
    {
        if (i == s.size())
            return sum == k;

        int ans = 0;
        string r = "";
        for (int j = i; j < s.size(); j++)
        {
            r += s[j];
            ans |= rec(s, k, j + 1, sum + stoi(r));
        }
        return ans;
    }

public:
    int punishmentNumber(int n)
    {
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int sq = i * i;
            string s = to_string(sq);
            if (rec(s, i, 0, 0))
                ans += sq;
        }
        return ans;
    }
};