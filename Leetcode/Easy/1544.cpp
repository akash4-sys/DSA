#include "../../headers.h"

class Solution
{
public:
    string makeGood(string s, int j = 0)
    {
        for(char c: s)
            if(j > 0 && abs(c - s[j - 1]) == 32)
                --j;
            else s[j++] = c;
        return s.substr(0, j);
    }
};

class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        for (char c : s)
            if (st.size() && ((isupper(st.top()) && islower(c)) || (isupper(c) && islower(st.top()))) && (tolower(st.top()) == tolower(c)))
                st.pop();
            else
                st.push(c);

        string ans = "";
        while (!st.empty())
            ans = st.top() + ans, st.pop();
        return ans;
    }
};

// @lc app=leetcode id=1544 lang=cpp