#include "../../headers.h"

// My approach,  TLE on last testcase
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int tlen = t.length(), slen = s.length();
        if (tlen > slen)
            return "";

        string ans = "";
        unordered_map<char, int> tmap;
        for (char c : t)
            tmap[c]++;

        int st = 0, end = tlen - 1, len = INT_MAX;
        while (end < slen)
        {
            string r = s.substr(st, (end - st + 1));
            unordered_map<char, int> rmap;
            for (char c : r)
                if (tmap.count(c) > 0)
                    rmap[c]++;

            bool flag = true;
            for (auto x : tmap)
                if ((rmap[x.first] - x.second) < 0)
                    flag = false;

            if (flag)
            {
                if (len > r.length())
                    ans = r, len = ans.length();
                st++;
                continue;
            }
            end++;
        }
        return ans;
    }
};




// PRO Approach
class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> mp(128);
        int slen = s.length(), i = 0, j = 0, len = INT_MAX, cnt = 0, st = -1;

        for (char c : t)
            mp[c]++;

        while(j < slen)
        {
            cnt += --mp[s[j++]] >= 0;
            while(cnt == t.length())
            {
                if((j - i) < len)
                    len = j - i, st = i;
                cnt -= ++mp[s[i++]] > 0;
            }
        }
        return st == -1 ? "" : s.substr(st, len);
    }
};