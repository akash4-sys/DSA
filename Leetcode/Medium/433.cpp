// #include "../../headers.h"

class Solution
{
public:
    int minMutation(string s, string e, vector<string> &bank)
    {
        unordered_map<string, int> mp;
        queue<string> q;
        mp[s] = 0;
        q.push(s);
        while (!q.empty())
        {
            s = q.front();
            q.pop();
            for (auto r : bank)
            {
                if (mp.count(r))
                    continue;
                int d = 0;
                for (int i = 0; i < 8; i++)
                    d += (s[i] != r[i]);
                if (d == 1)
                {
                    if (r == e)
                        return mp[s] + 1;
                    mp[r] = mp[s] + 1, q.push(r);
                }
            }
        }
        return -1;
    }
};

// @lc app=leetcode id=433 lang=cpp