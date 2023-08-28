#include "headers.h"

class Solution
{
public:
    bool isGood(vector<int> &v)
    {
        int cnt[201] = {0}, n = v.size() - 1;
        for (int x : v)
            cnt[x]++;

        return all_of(begin(cnt) + 1, begin(cnt) + n, [](int c) {
            return c == 1;
        }) && cnt[n] == 2;
    }
};

class Solution
{
public:
    bool isGood(vector<int> &v)
    {
        unordered_map<int, int> mp; 
        for (int n : v)
            mp[n]++;

        for (int i = 1; i < v.size() - 1; i++)
            if (mp[i] != 1)
                return 0;
        return mp[v.size() - 1] == 2;
    }
};