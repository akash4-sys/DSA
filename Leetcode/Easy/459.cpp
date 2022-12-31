#include "../../headers.h"

class Solution
{
    void zAlgorithm(string s, vector<int> &zArray)
    {
        int n = s.size(), x = 0, y = 0;
        for (int i = 1; i < n; i++)
        {
            zArray[i] = max(0, min(zArray[i - x], y - i + 1));
            while (i + zArray[i] < n && s[zArray[i]] == s[i + zArray[i]])
                x = i, y = i + zArray[i], zArray[i]++;
        }
    }

public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        vector<int> zArray(n);
        zAlgorithm(s, zArray);

        for (int i = 1; i <= n / 2; i++)
            if (zArray[i] + zArray[n - i] == n)
                return 1;
        return 0;
    }
};


class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s + s).substr(1, s.size() * 2 - 2).find(s) != -1;
    }
};