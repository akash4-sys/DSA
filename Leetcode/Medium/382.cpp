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
    ListNode *h;
    int len = 0;
    Solution(ListNode *head)
    {
        h = head;
    }

    int getRandom()
    {
        ListNode *curr = h;
        int ans = 0, n = 1;
        while(curr)
        {
            if(rand() % n  == 0)
                ans = curr->val;
            n++;
            curr = curr->next;
        }
        return ans;
    }
};