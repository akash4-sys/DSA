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
    ListNode *removeElements(ListNode *head, int val)
    {
        while(head && head->val == val)
            head = head->next;
        
        ListNode *curr = head;
        while(curr)
            (curr->next && curr->next->val == val) ? curr->next = curr->next->next : curr = curr->next;
        return head;
    }
};