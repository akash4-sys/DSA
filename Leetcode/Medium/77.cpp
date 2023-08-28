#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> v(k, 0);
        for (int i = 0; i >= 0;)
        {
            v[i]++;
            i -= v[i] > n;
            if (i == k - 1)
                ans.push_back(v);
            else
                ++i, v[i] = v[i - 1];
        }
        return ans;
    }
};



class Solution
{
    vector<vector<int>> ans;
    void rec(int n, int k, int it, vector<int> &v)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        for (int i = it; i <= n; i++)
        {
            v.push_back(i);
            rec(n, k, i + 1, v);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> v;
        rec(n, k, 1, v);
        return ans;
    }
};