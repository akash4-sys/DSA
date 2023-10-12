#include "../../headers.h"

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& v, vector<int>& p)
    {
        vector<int> st, en, ans;
        for (auto t : v)
            st.push_back(t[0]), en.push_back(t[1] + 1);
        
        sort(st.begin(), st.end());
        sort(en.begin(), en.end());
        for (auto n : p)
        {
            int i = upper_bound(st.begin(), st.end(), n) - st.begin();
            int j = upper_bound(en.begin(), en.end(), n) - en.begin();
            ans.push_back(i - j);
        }
        return ans;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& v, vector<int>& p)
    {
        map<int, int> mp;
        for (auto r : v)
            mp[r[0]]++, mp[r[1] + 1]--;
        
        vector<int> ans, time, pf;
        int sum = 0, j = 0;
        for (auto [t, c] : mp)
            time.push_back(t), pf.push_back(sum += c);
        
        for (auto n : p)
            ans.push_back(pf[upper_bound(time.begin(), time.end(), n) - time.begin() - 1]);
        return ans;
    }
};