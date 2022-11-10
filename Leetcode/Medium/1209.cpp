#include "../../headers.h"

class Solution
{
public:
    string removeDuplicates(string s, int k, int i = 0)
    {
        vector<int> ct(s.size());
        for(char c: s)
        {
            s[i] = c;
            ct[i] = (i > 0 && s[i - 1] == c) ? ct[i - 1] + 1 : 1;
            if(ct[i] == k)
                i -= k;
            i++;
        }
        return s.substr(0, i);
    }
};



// Time Complexity O(N)
// Space Complexity O(N)
class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        vector<pair<char, int>> st = {{'#', 0}};
        for (char c : s)
            if(st.back().first != c)
                st.push_back({c, 1});
            else if(++st.back().second == k)
                st.pop_back();

        string ans = "";
        for(auto &[c, ct]: st)
            ans += string(ct, c);
        return ans;
    }
};



class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        for (char c : s)
        {
            int ct = 1;
            while (!st.empty() && st.top().first == c)
                ct += st.top().second, st.pop();
            if (ct != k)
                st.push({c, ct});
        }

        string ans = "";
        while (!st.empty())
            ans = string(st.top().second, st.top().first) + ans, st.pop();
        return ans;
    }
};

// @lc app=leetcode id=1209 lang=cpp