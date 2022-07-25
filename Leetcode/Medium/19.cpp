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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* node = head, *list = head;
        int sz = 0, i = 0;
        while(node) 
        {
            sz++;
            node = node -> next;
        }
        
        if(sz == n)
            return head->next;

        while(i < (sz-n-1))
        {
            list = list -> next;
            i++;
        }
        list->next = list ->next -> next;
        return head;
    }
};