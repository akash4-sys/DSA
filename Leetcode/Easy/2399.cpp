#include "headers.h"

class Solution
{
public:
    bool checkDistances(string s, vector<int> &v)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.count(s[i]) == 1)
                if ((i - mp[s[i]] - 1) != v[s[i] - 97])
                    return false;
                else
                    mp[s[i]] = i;
        }
        return true;
    }
};

// Without map

class Solution
{
public:
    bool checkDistances(string s, vector<int> &v)
    {
        int mp[26] = {};
        for (int i = 0; i < s.size(); i++)
        {
            int x = s[i] - 97;
            if (mp[x] > 0 && i - mp[x] != v[x])
                return false;
            mp[x] = i + 1;
        }
        return true;
    }
};