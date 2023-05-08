#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &a, vector<int> &b)
    {
        vector<int> x, y;
        set<int> s1(a.begin(), a.end()), s2(b.begin(), b.end());
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(x));
        set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), back_inserter(y));
        return {x, y};
    }
};


class Solution
{
    vector<int> push(vector<int> &a, vector<int> &b)
    {
        unordered_set<int> st, res;
        for (int n : b)
            st.insert(n);
        for (int n : a)
            if (st.find(n) == st.end())
                    res.insert(n);
        return vector<int>(res.begin(), res.end());
    }

public:
    vector<vector<int>> findDifference(vector<int> &a, vector<int> &b)
    {
        return {push(a, b), push(b, a)};
    }
};