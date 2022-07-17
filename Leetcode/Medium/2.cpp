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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int c = 0;
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        
        while(l1 != NULL || l2 != NULL || c != 0)
        {
            int a = 0, b = 0;
            a = l1 ? l1->val : 0;
            l1 = l1 ? l1->next : nullptr;
            b = l2 ? l2->val: 0;
            l2 = l2 ? l2->next : nullptr;
            
            int sum = c + a + b;
            c = sum/10;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
        }
        return ans->next;
    }
};