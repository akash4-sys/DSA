#include "../../headers.h"

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
    Node *dfs(vector<vector<int>> &grid, int i, int j, int len)
    {
        if (len == 1)
            return new Node(grid[i][j], 1);

        Node *tl = dfs(grid, i, j, len / 2);
        Node *tr = dfs(grid, i, j + len / 2, len / 2);
        Node *bl = dfs(grid, i + len / 2, j, len / 2);
        Node *br = dfs(grid, i + len / 2, j + len / 2, len / 2);

        int x = tl->val;
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tr->val == x && bl->val == x && br->val == x)
            return new Node(x, 1);
        return new Node(0, 0, tl, tr, bl, br);
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        return dfs(grid, 0, 0, grid.size());
    }
};