#include "../../headers.h"

class Solution
{
public:
    int countDistinctIntegers(vector<int> &v)
    {
        unordered_set<int> st(begin(v), end(v));
        for(auto n: v)
        {
            string s = to_string(n);
            reverse(s.begin(), s.end());
            st.insert(stoi(s));
        }
        return st.size();
    }
};