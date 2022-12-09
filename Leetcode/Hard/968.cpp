#include "../../headers.h"
#include "../../treestructure.h"

// -1 - You need a camera
// 0 - You have a camera
// 1 - You are covered

// @ Even if one of the childs needs camera the it's better to give camera to parent

class Solution
{
    int ans = 0;
    int minCamera(TreeNode *root)
    {
        if(!root)
            return 1;
        int l = minCamera(root->left);
        int r = minCamera(root->right);
        if(l == -1 || r == -1)              // if either just left or right child needs a camera than parent needs a camera to cover itself and childs
        {
            ans++;
            return 0;
        }
        if(l == 0 || r == 0)        // if either left or right child has a camera than parent is already covered
            return 1;
        return -1;          // last case left is that you need a camera
    }

public:
    int minCameraCover(TreeNode *root)
    {
        // it means that when the you finally reach the root node it says that it needs a camera to it's parent
        // since it doesn't have one we simply provide it to it
        return ans += minCamera(root) == -1 ? 1 : 0;
    }
};