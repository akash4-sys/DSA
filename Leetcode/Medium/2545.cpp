#include "headers.h"

class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &m, int k)
    {
        sort(m.begin(), m.end(), [&](auto &a, auto &b){ 
            return a[k] > b[k]; 
        });
        return m;
    }
};

// Manual
class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &m, int k)
    {
        vector<vector<int>> ans;
        map<int, int, greater<int>> mp;
        for (int i = 0; i < m.size(); i++)
            mp[m[i][k]] = i;

        for (auto &[n, it] : mp)
            ans.push_back(m[it]);
        return ans;
    }
};