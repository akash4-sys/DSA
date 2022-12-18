#include "../../headers.h"

class BinaryIndexedTree
{
    vector<int> bit;
    int n;

public:
    BinaryIndexedTree(int _n): n(_n), bit(_n, 0) {}

    int getSum(int i)
    {
        int sum = 0;
        for (; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    void add(int i)
    {
        for (; i < n; i += i & (-i))
            bit[i]++;
    }
};

class Solution
{
public:
    vector<int> countRectangles(vector<vector<int>> &rect, vector<vector<int>> &pts)
    {
        int n = rect.size(), m = pts.size();
        BinaryIndexedTree BIT(101);
        vector<int> ans(m, 0), idx(m, 0);

        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](const int &a, const int &b){
            return pts[a][0] > pts[b][0];
        });
        sort(rect.begin(), rect.end(), [&](const auto &a, const auto &b){
            return a[0] > b[0];
        });

        for (int i = 0, j = 0; i < m; i++)
        {
            while (j < n && rect[j][0] >= pts[idx[i]][0])
                BIT.add(rect[j++][1] + 1);
            ans[idx[i]] = j - BIT.getSum(pts[idx[i]][1]);
        }
        return ans;
    }
};



// Without BIT
class Solution 
{
public:
    vector<int> countRectangles(vector<vector<int>>& rect, vector<vector<int>>& pts) 
    {
        vector<int> ans;
        vector<vector<int>> umap(101);
        for (auto &r: rect)
            umap[r[1]].push_back(r[0]);
        
        for (int i = 0; i < 101; i++)
            sort(begin(umap[i]), end(umap[i]));
        
        for (auto &p: pts) 
        {
            int sum = 0;
            for (int i = p[1]; i < 101; i++) 
            {
                auto lb = lower_bound(begin(umap[i]), end(umap[i]), p[0]);
                sum += end(umap[i]) - lb;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};