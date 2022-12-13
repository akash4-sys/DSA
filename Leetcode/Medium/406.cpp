#include "../../headers.h"

// Same complexity but short code
class Solution 
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) 
    {
        sort(v.begin(), v.end(), [&](const auto &a, const auto &b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> ans;
        for(auto n : v)
            ans.insert(ans.begin() + n[1], n);
        return ans;
    }
};


// Time Complexity - O(N^2logN)
// Space Complexity - O(N^2)

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end(), [&](const auto &a, const auto &b){
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
        });

        vector<vector<int>> ans;
        for (int i = 0; i < v.size(); i++)
        {
            int h = v[i][0], p = v[i][1], j = 0, n = ans.size();

            while(j < n && (p != 0 || ans[j][0] < h))
                p -= (ans[j][0] >= h), j++;

            j = j == 0 ? n : j;
            ans.insert(ans.begin() + j, v[i]);
        }
        return ans;
    }
};