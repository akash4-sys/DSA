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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *ans = new ListNode();
        ListNode *r, *l = ans;
        ans -> next = head;
        for (int i = 0; i < left - 1; i++)
        {
            l = l->next;
        }
        r = l->next;
        for (int i = 0; i < right - left; i++)
        {
            ListNode *temp = l->next;
            l->next = r->next;
            r->next = r->next->next;
            l->next->next = temp;
        }
        return ans->next;
    }
};