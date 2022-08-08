#include "../../headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode *o = head, *e = head->next, *eh = e;
        while(e && e->next)
        {
            o->next = e->next;
            e->next = e->next->next;
            o = o->next;
            e = e->next;
        }
        o->next = eh;
        return head;
    }
};