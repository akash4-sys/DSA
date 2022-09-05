#include "../../headers.h"

// Time Complexity - O(N * 26)
// Space Complexity - O(1)

class Solution
{
    bool checkMap(int smap[], int pmap[])
    {
        for (int i = 0; i < 26; i++)
            if (pmap[i] - smap[i] != 0)
                return false;
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.length() > s.length())
            return {};

        vector<int> ans;
        int r = p.length(), pmap[26], smap[26];
        memset(pmap, 0, sizeof(pmap));
        memset(smap, 0, sizeof(pmap));

        for (int i = 0; i < r; i++)
            pmap[p[i] - 'a']++, smap[s[i] - 'a']++;

        if (checkMap(smap, pmap))
            ans.push_back(0);

        for (int i = 1; i <= s.size() - r; i++)
        {
            smap[s[i - 1] - 'a'] -= 1;
            smap[s[i + r - 1] - 'a'] += 1;
            if (checkMap(smap, pmap))
                ans.push_back(i);
        }
        return ans;
    }
};


// Same Time Complexity Cleaner Code
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.length() > s.length())
            return {};

        vector<int> ans, smap(26, 0), pmap(26, 0);
        int r = p.length();     

        for (int i = 0; i < r; i++)
            pmap[p[i] - 'a']++, smap[s[i] - 'a']++;

        if (smap == pmap)
            ans.push_back(0);

        for (int i = 1; i <= s.size() - r; i++)
        {
            smap[s[i - 1] - 'a'] -= 1;
            smap[s[i + r - 1] - 'a'] += 1;
            if (smap == pmap)
                ans.push_back(i);
        }
        return ans;
    }
};