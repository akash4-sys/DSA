#include "../../headers.h"
#include "../../linkedlist.h"

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        auto l = new ListNode(0);
        l->next = head;
        unordered_map<int, ListNode*> mp;
        int sum = 0;
        for (auto h = l; h; h = h->next)
            mp[sum += h->val] = h;
        
        sum = 0;
        for (auto h = l; h; h = h->next)
            h->next = mp[sum += h->val]->next;
        return l->next;
    }
};