#include "headers.h"

class Solution
{
public:
    int distinctIntegers(int n)
    {
        return max(n - 1, 1);
    }
};


class Solution
{
public:
    int distinctIntegers(int n)
    {
        unordered_set<int> st = {n};
        int c = st.size();
        while (1)
        {
            for (auto x : st)
                for (int i = 1; i < x; i++)
                    if (x % i == 1)
                        st.insert(i);
            if (st.size() == c)
                return st.size();
            c = st.size();
        }
        return -1;
    }
};