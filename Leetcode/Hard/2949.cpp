#include "../../headers.h"

static unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
class Solution
{
public:
    long long beautifulSubstrings(string &s, int k)
    {
        long long ans = 0, v = 0, len = 1;
        for (; (len * len) % (k * 4); len++);

        vector<unordered_map<int, int>> mp(len);
        mp[len - 1][0] = 1;
        for (int i = 0; i < s.size(); i++)
        {
            v += vowels.find(s[i]) != vowels.end() ? 1 : -1;
            ans += mp[i % len][v]++;
        }
        return ans;
    }
};

// TLE
class Solution
{
public:
    long long beautifulSubstrings(string &s, int k)
    {
        long long ans = 0, v = 0, c = 0;
        vector<int> d = {0};
        for (char &ch : s) {
            vowels.find(ch) != vowels.end() ? v++ : c++;
            d.push_back(v - c);
        }

        unordered_map<int, vector<int>> mp;
        for (long long i = 0; i < d.size(); i++)
        {
            if (mp.find(d[i]) != mp.end())
                for (int j : mp[d[i]])
                    ans += (((i - j) * (i - j)) / 4) % k == 0;
            mp[d[i]].push_back(i);
        }
        return ans;
    }
};