#include "headers.h"

class Solution
{
public:
    int minLength(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            char x = st.top();
            if (!st.empty() && ((x == 'A' && c == 'B') || (x == 'C' && c == 'D'))) {
                st.pop();
                continue;
            }
            else {
                st.push(c);
            }
        }
        return st.size();
    }
};