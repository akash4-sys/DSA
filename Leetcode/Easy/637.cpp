#include "../../headers.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// DFS
class Solution
{
    vector<double> ans;
    vector<int> count;

public:
    vector<double> averageOfLevels(TreeNode *root, int lvl = 0)
    {
        if (!root)
            return {};
        if (count.size() <= lvl)
        {
            count.push_back(0);
            ans.push_back(0.0);
        }

        count[lvl] += 1;
        ans[lvl] = ((ans[lvl] * (count[lvl] - 1)) + root->val) / count[lvl];
        averageOfLevels(root->right, lvl + 1);
        averageOfLevels(root->left, lvl + 1);
        return ans;
    }
};


// BFS

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            long long sum = 0;
            int c = q.size(), n = q.size();
            while (n--)
            {
                TreeNode *r = q.front();
                q.pop();
                sum += r->val;
                if (r->left)
                    q.push(r->left);
                if (r->right)
                    q.push(r->right);
            }
            ans.push_back(sum / (double)c);
        }
        return ans;
    }
};