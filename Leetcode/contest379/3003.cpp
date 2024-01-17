#include "../../headers.h"

class Solution
{
    unordered_map<long long, int> dp;
    string s;
    int k;

    int rec(long long i, long long mask, bool canChange)
    {
        if (i == s.size())
            return 0;
        
        long long key = (i << 27) | (mask << 1) | canChange;
        if (dp.count(key))
            return dp[key];
        
        int cnt = __builtin_popcount(mask | (1 << (s[i] - 'a'))), res = 0;
        if (cnt > k)
            res = rec(i + 1, 1 << (s[i] - 'a'), canChange) + 1;
        else
            res = rec(i + 1, mask | (1 << (s[i] - 'a')), canChange);

        for (int j = 0; j < 26 && canChange; j++)
        {
            int newMask = mask | (1 << j), newCnt = __builtin_popcount(newMask);
            if (newCnt > k)
                res = max(res, rec(i + 1, 1 << j, 0) + 1);
            else
                res = max(res, rec(i + 1, newMask, 0));
        }
        return dp[key] = res;
    }

public:
    int maxPartitionsAfterOperations(string &s, int k)
    {
        this->s = s, this->k = k;
        return rec(0, 0, 1) + 1;
    }
};