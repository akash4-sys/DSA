#include "headers.h"

class Solution 
{
public:
    int distinctAverages(vector<int>& v) 
    {
        unordered_set<double> st;
        sort(v.begin(), v.end());
        for(int l = 0, r = v.size() - 1; l < r; l++, r--)
            st.insert((v[l] + v[r]) / 2.0);
        return st.size();
    }
};