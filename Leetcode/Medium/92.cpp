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
    ListNode *reverseBetween(ListNode *head, int l, int r)
    {
        auto h = new ListNode(0);
        h->next = head;

        auto prev = h;
        for (int i = 1; i < l; i++)
            prev = prev->next;
        
        auto curr = prev->next;
        for (; l < r; l++)
        {
            auto temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return h->next;
    }
};