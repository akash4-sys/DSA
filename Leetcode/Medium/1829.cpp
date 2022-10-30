#include "../../headers.h"

class Solution 
{
public:
    vector<int> getMaximumXor(vector<int>& v, int bit)
    {
        vector<int> ans(v.size());
        int k = (1 << bit) - 1;
        for(int i = 0; i < v.size(); i++)
            ans[v.size() - i - 1] = k ^= v[i];
        return ans;
    }
};


class Solution 
{
public:
    vector<int> getMaximumXor(vector<int>& v, int bit)
    {
        vector<int> ans;
        int x = 0, k = (1 << bit) - 1;
        for(int n: v)
            x ^= n;
        for(int i = v.size() - 1; i >= 0; i--)
            ans.push_back(x ^ k), x ^= v[i];
        return ans;
    }
};