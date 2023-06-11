#include "headers.h"

class Solution
{
public:
    bool isFascinating(int n)
    {
        string s = to_string(n) + to_string(2 * n) + to_string(3 * n);
        unordered_set<char> st(s.begin(), s.end());
        return st.size() == 9 && s.size() == 9 && st.find('0') == st.end();
    }
};