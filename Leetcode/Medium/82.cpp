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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans = new ListNode(0);
        ListNode *h = ans;

        while(head)
        {
            int temp = head->val;
            if(head -> next && head -> next -> val == temp)
                while(head && head -> val == temp)
                    head = head -> next;
            else
            {
                h -> next = head;
                h = head;
                head = head -> next;
            }
        }
        return ans->next;
    }
};