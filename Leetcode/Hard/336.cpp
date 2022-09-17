#include "../../headers.h"

// Author - https://leetcode.com/problems/palindrome-pairs/discuss/2585571/C%2B%2B-TLE-and-barely-passing-solution-XD


// Only passing solution
// Trie failling as well

class Solution
{
    bool isValid(string t, int l, int r)
    {
        while(l < r)
            if(t[l++] != t[r--])
                return false;
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string> &w)
    {
        vector<vector<int>> ans;
        unordered_map<string, int> mp;
        set<int> st;
        for (int i = 0; i < w.size(); i++)
            mp[w[i]] = i, st.insert(w[i].size());

        for (int i = 0; i < w.size(); i++)
        {
            string r = w[i];
            int n = r.size();
            reverse(begin(r), end(r));
            if (mp.count(r) && mp[r] != i)
                ans.push_back({i, mp[r]});
            auto a = st.find(n);
            for (auto it = st.begin(); it != a; it++)
            {
                int d = *it;
                if (isValid(r, 0, n - d - 1) && mp.count(r.substr(n - d)))
                    ans.push_back({i, mp[r.substr(n - d)]});
                if(isValid(r, d, n - 1) && mp.count(r.substr(0, d)))
                    ans.push_back({mp[r.substr(0, d)], i});
            }
        }
        return ans;
    }
};