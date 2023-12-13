#include "../../headers.h"

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &v)
    {
        int cnt[101] = {0}, p = 0;
        for (int a : v)
            cnt[a]++;
        
        for (int i = 0; i <= 100; i++)
            p += cnt[i] / 2;
        return {p, (int)v.size() - (p * 2)};
    }
};