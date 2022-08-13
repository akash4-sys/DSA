#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        if (!head)
            return grid;

        for (int i = 0; head; i++)
        {
            for (int j = i; j < n - i && head; j++, head = head->next)
                grid[i][j] = head->val;

            for (int j = i + 1; j < m - i && head; j++, head = head->next)
                grid[j][n - i - 1] = head->val;

            for (int j = n - i - 2; m - i - 1 != i && j >= i && head; j--, head = head->next)
                grid[m - i - 1][j] = head->val;

            for (int j = m - i - 2; n - i - 1 != i && j > i && head; j--, head = head->next)
                grid[j][i] = head->val;
        }
        return grid;
    }
};