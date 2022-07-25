#include "../../headers.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s)
        {
            if(c == '{' || c == '[' || c == '(')
                st.push(c);
            else if(!st.size() || (c == ')' && st.top() != '(') || (c == '}' && st.top() != '{') || (c == ']' && st.top() != '['))
                return false;
            else
                st.pop();
        }
        if(st.size())
            return false;
        return true;
    }
};