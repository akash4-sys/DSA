#include "../../headers.h"

class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;
        string ans = "";
        for(char c: s)
        {
            if(c == ']')
            {
                string q, r;
                int n = 0, p = 1;
                while(st.top() != '[')
                    q = st.top() + q, st.pop();
                st.pop();
                while(!st.empty() && isdigit(st.top()))
                    n = ((st.top() - '0') * p) + n, p *= 10, st.pop();
                while(n--)
                    r += q;
                for(int i = 0; i < r.size(); i++)
                    st.push(r[i]);
            }
            else
                st.push(c);
        }

        while(!st.empty())
            ans = st.top() + ans, st.pop();
        return ans;
    }
};

// @lc app=leetcode id=394 lang=cpp