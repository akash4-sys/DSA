#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Insertion Sort
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode ans;
        while (head)
        {
            auto st = head, curr = &ans;
            head = head->next;
            while(curr->next && curr->next->val < st->val)
                curr = curr->next;
            st->next = curr->next;
            curr->next = st;
        }
        return ans.next;
    }
};