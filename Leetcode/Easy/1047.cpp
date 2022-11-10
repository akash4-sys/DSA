#include "../../headers.h"


// A good way to solve stack string question
// monotonic stack
class Solution
{
public:
    string removeDuplicates(string s, int i = 0)
    {
        for(char c: s)
            if(i > 0 && s[i - 1] == c)
                --i;
            else s[i++] = c;
        return s.substr(0, i);
    }
};



class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (char c : s)
            if(!st.empty() && st.top() == c)
                st.pop();
            else
                st.push(c);
                
        string ans = "";
        while (!st.empty())
            ans = st.top() + ans, st.pop();
        return ans;
    }
};


class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            int f = 1;
            while (!st.empty() && st.top() == c)
                f = 0, st.pop();
            if (f)
                st.push(c);
        }

        string ans = "";
        while (!st.empty())
            ans = st.top() + ans, st.pop();
        return ans;
    }
};

// @lc app=leetcode id=1047 lang=cpp