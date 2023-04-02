#include "headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &v)
    {
        vector<vector<int>> ans;
        vector<int> cnt(v.size() + 10);
        for (int n : v)
        {
            if (ans.size() <= cnt[n])
                ans.push_back({});
            ans[cnt[n]++].push_back(n);
        }
        return ans;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &v)
    {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (int n : v)
            mp[n]++;
        
        for (auto &[n, c] : mp)
            for (int i = 0; i < c; i++)
                if (ans.size() > i)
                    ans[i].push_back(n);
                else
                    ans.push_back({n});
        return ans;
    }
};