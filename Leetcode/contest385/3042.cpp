#include "../../headers.h"

class Solution
{
    bool isPrefixAndSuffix(string &p, string &s)
    {
        int n = s.size(), m = p.size();
        if (m > n)
            return 0;
        
        for (int i = 0; i < m; i++)
            if (p[i] != s[i] || p[m - i - 1] != s[n - i - 1])
                return 0;
        return 1;
    }

public:
    int countPrefixSuffixPairs(vector<string> &v)
    {
        int ans = 0, n = v.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isPrefixAndSuffix(v[i], v[j]))
                    ans++;
        return ans;
    }
};