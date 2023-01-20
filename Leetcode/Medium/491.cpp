#include "../../headers.h"

// Time Complexity - O(2^N + NlogN)
// Space Complexity - O(2^N)

class Solution
{
    
public:
    vector<vector<int>> findSubsequences(vector<int> &v)
    {
        vector<vector<int>> ans;
        for (int i = 1; i < (1 << v.size()); i++)
        {
            vector<int> sub = {-101};
            for (int j = 0; j < v.size(); j++)
                if (i & (1 << j) && sub.back() <= v[j])
                    sub.push_back(v[j]);
            if (sub.size() > 2)
                ans.push_back({sub.begin() + 1, sub.end()});
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;  
    }
};


// Time Complexity - O(2^N + NlogN)
// Space Complexity - O(2^N)

class Solution
{
    vector<vector<int>> ans;
    void generateSub(vector<int> &v, vector<int> &sub, int i)
    {
        if (i == v.size())
        {
            if (sub.size() > 2)
                ans.push_back({sub.begin() + 1, sub.end()});
            return;
        }
        if (sub.back() <= v[i])
        {
            sub.push_back(v[i]);
            generateSub(v, sub, i + 1);
            sub.pop_back();
        }
        generateSub(v, sub, i + 1);
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int> &v)
    {
        vector<int> sub = {-101};
        generateSub(v, sub, 0);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;  
    }
};