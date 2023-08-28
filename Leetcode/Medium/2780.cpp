#include "headers.h"

class Solution
{
public:
    int minimumIndex(vector<int> &v)
    {
        unordered_map<int, int> mp1, mp;
        for (int a : v)
            mp1[a]++;

        for (int i = 0; i < v.size(); i++)
        {
            int x = ++mp[v[i]] * 2;
            int y = --mp1[v[i]] * 2;
            if (x > i + 1 && y > v.size() - i - 1)
                return i;
        }
        return -1;
    }
};


class Solution
{
public:
    int minimumIndex(vector<int> &v)
    {
        int maj = v[0], c = 0;
        for (int a : v)
        {
            c += (maj == a) ? 1 : -1;
            if (!c)
                maj = a, c = 1;
        }

        int cnt = count(v.begin(), v.end(), maj), n = v.size();
        for (int i = 0, c = 0; i < n; i++)
        {
            c += v[i] == maj;
            if (c * 2 > i + 1 && (cnt - c) * 2 > n - i - 1)
                return i;
        }
        return -1;
    }
};