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
    
    void vec(ListNode *node, vector<int> &v)
    {
        for(ListNode *curr = node; curr != NULL; curr = curr -> next)
        {
            v.push_back(curr->val);
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> values;
        for(ListNode *i: lists)
        {
            vec(i, values);
        }
        
        sort(values.begin(), values.end(), greater<int>());
        
        ListNode *head = new ListNode();
        ListNode *temp = head;
        
        for(int i = values.size()-1; i >= 0; i--)
        {
            temp->next = new ListNode(values[i]);
            temp = temp -> next;
        }
        
        return head->next;
    }
};