#include "../../headers.h"

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &p, vector<int> &t)
    {
        sort(p.begin(), p.end());
        multiset<int> st;
        for (int &a : t)
            st.insert(a);
        
        int ans = 0;
        for (int &a : p)
            if (auto it = st.lower_bound(a); it != st.end())
                st.erase(it), ans++;
        return ans;
    }
};