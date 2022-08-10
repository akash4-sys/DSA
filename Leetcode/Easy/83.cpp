#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *h = head;
        while(h)
            (h->next && h->val == h->next->val) ? h->next = h->next->next : h = h->next;
        return head;
    }
};