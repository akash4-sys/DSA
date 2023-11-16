#include "../../headers.h"

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &v)
    {
        vector<string> ans;
        sort(v.begin(), v.end());
        unordered_map<string, vector<int>> mp;
        for (auto &a : v)
            mp[a[0]].push_back(stoi(a[1]));

        for (auto &[s, t] : mp)
            for (int i = 0; i < t.size() - 2 && t.size() >= 3; i++)
            {
                int j = lower_bound(t.begin(), t.end(), t[i] + 100) - t.begin();
                if (j - i >= 3) {
                    ans.push_back(s);
                    break;
                }
            }
        return ans;
    }
};