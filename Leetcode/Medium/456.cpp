#include "../../headers.h"

class Solution
{
public:
    bool find132pattern(vector<int> &v)
    {
        stack<pair<int, int>> st;
        int cmin = INT_MAX;
        for (int n : v)
        {
            for (; !st.empty() && st.top().first <= n; st.pop());
            if (st.size() && n > st.top().second)
                return 1;
            st.push({n, cmin});
            cmin = min(cmin, n);
        }
        return 0;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    bool find132pattern(vector<int> &v)
    {
        map<int, int> mp;
        for (int n : v)
            mp[n]++;
        
        int mn = INT_MAX;
        for (int n : v)
        {
            if (--mp[n] == 0)
                mp.erase(n);
            if (mn < n)
            {
                auto it = mp.upper_bound(mn);
                if (it != mp.end() && it->first < n)
                    return 1;
            }
            mn = min(mn, n);
        }
        return 0;
    }
};