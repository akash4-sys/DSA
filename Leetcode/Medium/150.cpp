#include "../../headers.h"

class Solution
{
    int evaluate(string s, int x, int y)
    {
        if (s == "+")
            return x + y;
        if (s == "-")
            return y - x;
        if (s == "*")
            return (long)x * y;
        return y / x;
    }

public:
    int evalRPN(vector<string> &v)
    {
        stack<int> st;
        for (auto s : v)
        {
            if (s != "+" && s != "-" && s != "*" && s != "/")
            {
                int num = 0, sign = 1;
                if (s[0] == '-')
                    sign = -1, s[0] = '0';
                for (auto c : s)
                    num = num * 10 + (c - '0');
                num *= sign;
                st.push(num);
            }
            else
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(evaluate(s, x, y));
            }
        }
        return st.top();
    }
};



class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };

        stack<int> stack;
        for (string& s : tokens) 
        {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};